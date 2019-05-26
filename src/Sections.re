[@react.component]
let make = (~sections) => {
  switch (sections) {
  | None => "No sections" |> Util.ste
  | Some(sections) =>
    <div>
      {sections
       |> Array.map(section =>
            switch (section) {
            | None => "" |> Util.ste
            | Some(section) =>
              <div key={section##id}>
                <h2> {section##name |> Util.ste} </h2>
                <Cards cards={section##cards} />
              </div>
            }
          )
       |> React.array}
    </div>
  };
};