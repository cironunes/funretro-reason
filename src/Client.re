/* open ApolloLinks; */
open ApolloInMemoryCache;

/* Create an InMemoryCache */
let inMemoryCache = createInMemoryCache();

/* Create an HTTP Link */
let httpLink =
  ApolloLinks.createHttpLink(~uri="http://localhost:4000/graphql", ~credentials="include", ());

let instance =
  ReasonApollo.createApolloClient(
    ~link=httpLink,
    ~cache=inMemoryCache,
    (),
  );