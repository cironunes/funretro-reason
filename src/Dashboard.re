module Boards = [%graphql
  {|
    query getAllBoards {
      boards {
        name
        id
      }
    }
  |}
];

module BoardsQuery = ReasonApollo.CreateQuery(Boards);

let boardName = board => <div>board##name</div>;

[@react.component]
let make = () =>
  <BoardsQuery>
    ...{({result}) =>
      <div>
        <h1>{Util.ste("Dashboard")}</h1>
        <button>{"New board" |> Util.ste}</button>
        <NewBoard />
        {switch result {
        | Loading => "Loading" |> Util.ste
        | Error(error) => error##message |> Util.ste
        | Data(response) =>
          <div>
          {switch(response##boards) {
          | None => "Empty" |> Util.ste
          | Some(boards) =>
            <div>
              {boards |> Array.map(board =>
                switch(board) {
                | None => "" |> Util.ste
                | Some(board) =>
                  <div key={board##id}>
                    <a href={"board/" ++ board##id}>{board##name |> Util.ste}</a>
                  </div>
                }
              ) |> React.array}
            </div>
          }}
          </div>
        }}
      </div>
    }
  </BoardsQuery>;