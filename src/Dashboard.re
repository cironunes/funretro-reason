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

type state = {
  isCreatingBoard: bool,
};

type action =
  | ToggleNewBoardForm;

let boardName = board => <div>board##name</div>;

[@react.component]
let make = () => {
  let (state, dispatch) = React.useReducer((state, action) =>
    switch(action) {
    | ToggleNewBoardForm => {isCreatingBoard: !state.isCreatingBoard}
    },
    {isCreatingBoard: false},
  );
  <BoardsQuery>
    ...{({result}) =>
      <div>
        <h1>{Util.ste("Dashboard")}</h1>
        <button onClick={event => {
          ReactEvent.Mouse.preventDefault(event);
          dispatch(ToggleNewBoardForm);
        }}>{"New board" |> Util.ste}</button>

        {state.isCreatingBoard ? <NewBoard /> : React.null}

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
};