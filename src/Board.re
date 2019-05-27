module Board = [%graphql
  {|
    query Board($id: ID!) {
      board(id: $id) {
        name
        maxVotes
        sections{
          name
          id
          cards{
            id
            text
            votes{
              firstName
            }
            comments{
              id
              text
              author {
                id,
                firstName,
                lastName,
              }
            }
          }
        }
      }
    }
  |}
];

module BoardQuery = ReasonApollo.CreateQuery(Board);

[@react.component]
let make = (~id) => {
  let query = Board.make(~id=id, ());
  <BoardQuery variables=query##variables>
    ...{({result}) => {
      <div>
        {switch result {
        | Loading => "Loading" |> Util.ste
        | Error(error) => error##message |> Util.ste
        | Data(response) =>
        <div>
          {switch(response##board) {
          | None => "Not found" |> Util.ste
          | Some(board) =>
          <div>
            <h1>{board##name |> Util.ste}</h1>
            <span>{"Max votes: " |> Util.ste} {board##maxVotes |> string_of_int |> Util.ste}</span>
            <Sections sections={board##sections} boardId={id} />
          </div>
          }}
        </div>
        }}
      </div>
    }
    }
  </BoardQuery>
}