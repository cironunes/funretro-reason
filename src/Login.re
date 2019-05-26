open Belt.Option;

module Login = [%graphql
  {|
    mutation Login($email: String!, $password: String!){
      login(email: $email, password: $password) {
        firstName
        lastName
        id
        email
      }
    }
  |}
];

module LoginMutation = ReasonApollo.CreateMutation(Login);

type state = {
  email: string,
  password: string,
};

type action =
  | Email(string)
  | Password(string);

[@react.component]
let make = () => {
  let (state, dispatch) =
    React.useReducer(
      (state, action) =>
        switch (action) {
        | Email(email) => {...state, email}
        | Password(password) => {...state, password}
        },
      {email: "", password: ""},
    );
  <LoginMutation onCompleted={() => ReasonReactRouter.push("dashboard")}>
    ...{
         (mutation, {result}) =>
         <div>
            <span>
              {switch(result) {
              | NotCalled => "" |> Util.ste
              | Data(_) => "Logged in successfully" |> Util.ste
              | Error(_) => "Invalid email/password combination. Please try again" |> Util.ste
              | Loading => "Loading" |> Util.ste
              }}
            </span>
            <form
              onSubmit={
                event => {
                  ReactEvent.Form.preventDefault(event);
                  let login =
                    Login.make(
                      ~email=state.email,
                      ~password=state.password,
                      (),
                    );
                  mutation(~variables=login##variables, ()) |> ignore;
                }
              }>
              <div>
                <label> {"Email" |> Util.ste} </label>
                <input
                  type_="text"
                  placeholder="Email"
                  onChange={
                    e => dispatch(Email(ReactEvent.Form.target(e)##value))
                  }
                />
              </div>
              <div>
                <label> {"Password" |> Util.ste} </label>
                <input
                  type_="password"
                  placeholder="Password"
                  onChange={
                    e => dispatch(Password(ReactEvent.Form.target(e)##value))
                  }
                />
              </div>
              <button type_="submit"> {"Login" |> Util.ste} </button>
            </form>
          </div>
       }
  </LoginMutation>;
};