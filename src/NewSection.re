module CreateSection = [%graphql
  {|
    mutation CreateSection($name: String!, $boardId: ID!) {
      createSection(name: $name, boardId: $boardId) {
        name
      }
    }
  |}
];

module CreateSectionMutation = ReasonApollo.CreateMutation(CreateSection);

type state = {
  name: string,
};

type action =
  | Name(string);

[@react.component]
let make = (~boardId) => {
  let (state, dispatch) = React.useReducer((_state, action) =>
    switch (action) {
    | Name(name) => {name: name}
    },
    {name: ""},
  );
  <CreateSectionMutation>
    ...{
      (mutation, {result}) => {
        <div>
          <span>
            {switch (result) {
            | NotCalled => "" |> Util.ste
            | Data(_) => "Section created successfully" |> Util.ste
            | Error(_) => "Error" |> Util.ste
            | Loading => "Loading" |> Util.ste
            }}
          </span>
          <form onSubmit={event => {
            ReactEvent.Form.preventDefault(event);
            let createSection = CreateSection.make(~name=state.name, ~boardId=boardId, ());
            mutation(
              ~variables=createSection##variables,
              ~refetchQueries=[|"board(id: $id)"|],
              (),
            ) |> ignore;
          }}>
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
            <button type_="submit">{"Create section" |> Util.ste}</button>
          </form>
        </div>
      }
    }
  </CreateSectionMutation>
};
