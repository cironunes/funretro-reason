module NewCard = [%graphql
  {|
    mutation CreateCard($text: String!, $sectionId: ID!) {
      createCard(text: $text, sectionId: $sectionId) {
        text
      }
    }
  |}
];

module NewCardMutation = ReasonApollo.CreateMutation(NewCard);

type state = {
  text: string,
};

type action = 
  | Text(string);
[@react.component]
let make = (~sectionId) => {
  let (state, dispatch) = React.useReducer((_state, action) =>
  switch(action) {
  | Text(text) => {text: text}
  },
  {text: ""},
  );
  <NewCardMutation>
    ...{
      (mutation, {result}) =>
        <div>
          <span>
            {switch (result) {
            | NotCalled => "" |> Util.ste
            | Data(_) => "Card created successfully" |> Util.ste
            | Error(_) => "Error" |> Util.ste
            | Loading => "Loading" |> Util.ste
            }}
          </span>
          <form onSubmit={event => {
            ReactEvent.Form.preventDefault(event);
            let newCard = NewCard.make(~text=state.text, ~sectionId=sectionId, ());
            mutation(~variables=newCard##variables, ()) |> ignore;
          }}>
            <div>
              <textarea
                placeholder="Name"
                value={state.text}
                onChange={
                  e => dispatch(Text(ReactEvent.Form.target(e)##value))
                }
              />
            </div>
            // {state.text |> Util.ste}
            // {"board: " |> Util.ste} {boardId |> Util.ste}
            // {"section: " |> Util.ste} {sectionId |> Util.ste}
            <button type_="submit">{"Create card" |> Util.ste}</button>
          </form>
        </div>
    }
  </NewCardMutation>
};
