module CreateBoard = [%graphql
  {|
    mutation CreateBoard($name: String!, $maxVotes: Int!) {
      createBoard(name: $name, maxVotes: $maxVotes) {
        name,
        maxVotes
      }
    }
  |}
];

module CreateBoardMutation = ReasonApollo.CreateMutation(CreateBoard);

type state = {
  name: string,
  maxVotes: string,
};

type action =
  | Name(string)
  | MaxVotes(string);

[@react.component]
let make = () => {
  let (state, dispatch) = React.useReducer((state, action) =>
    switch (action) {
    | Name(name) => {...state, name}
    | MaxVotes(maxVotes) => {...state, maxVotes}
    },
    {name: "", maxVotes: "0"},
  );

  <CreateBoardMutation>
    ...{
      (mutation, {result}) => {
        <div>
          <span>
            {switch (result) {
            | NotCalled => "" |> Util.ste
            | Data(_) => "Board created successfully" |> Util.ste
            | Error(_) => "Error" |> Util.ste
            | Loading => "Loading" |> Util.ste
            }}
          </span>
          <form onSubmit={
            event => {
              ReactEvent.Form.preventDefault(event);
              let createBoard = CreateBoard.make(~name=state.name, ~maxVotes=int_of_string(state.maxVotes), ());
              mutation(
                ~variables=createBoard##variables,
                ~refetchQueries=[|"getAllBoards"|],
                (),
              ) |> ignore;
            }
          }>
            <div>
              <label> {Util.ste("Name")} </label>
              <input
                type_="text"
                placeholder="Name"
                value={state.name}
                onChange={
                  e => dispatch(Name(ReactEvent.Form.target(e)##value))
                }
              />
            </div>
            <div>
              <label> {Util.ste("Max votes")} </label>
              <input
                type_="number"
                placeholder="Max votes"
                value={state.maxVotes}
                onChange={
                  e => dispatch(MaxVotes(ReactEvent.Form.target(e)##value))
                }
              />
            </div>
            <button type_="submit">{"Create board" |> Util.ste}</button>
          </form>
        </div>
      }
    }
  </CreateBoardMutation>
};

