[@react.component]
let make = (~cards) => {
  switch(cards) {
  | None => "No cards" |> Util.ste
  | Some(cards) =>
  <div>
    <ul>
      {cards |> Array.map(card =>
        switch(card) {
        | None => "" |> Util.ste
        | Some(card) => 
        <Card
          key={card##id}
          id={card##id}
          text={card##text}
          comments={card##comments}
          votes={card##votes}
        />
        }
      ) |> React.array}
    </ul>
  </div>
  }
}