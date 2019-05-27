type state = {
  isCreatingNewSection: bool,
  sectionIdForNewCard: string,
};

type action =
  | ToggleNewSectionForm;

[@react.component]
let make = (~sections, ~boardId) => {
  let (state, dispatch) = React.useReducer((state, action) =>
    switch(action) {
    | ToggleNewSectionForm => {...state, isCreatingNewSection: !state.isCreatingNewSection}
    },
    {isCreatingNewSection: false, sectionIdForNewCard: ""},
  );
  switch (sections) {
  | None => "No sections" |> Util.ste
  | Some(sections) =>
    <div>
      <button onClick={event => {
        ReactEvent.Mouse.preventDefault(event);
        dispatch(ToggleNewSectionForm);
      }}>{"New section" |> Util.ste}</button>
      {state.isCreatingNewSection ? <NewSection boardId={boardId} /> : React.null}

      {sections
       |> Array.map(section =>
            switch (section) {
            | None => "" |> Util.ste
            | Some(section) =>
              <div key={section##id}>
                <h2> {section##name |> Util.ste} </h2>

                <NewCard sectionId={section##id} />
                <Cards cards={section##cards} />
              </div>
            }
          )
       |> React.array}
    </div>
  };
};