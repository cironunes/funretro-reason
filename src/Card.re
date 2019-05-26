[@react.component]
let make = (~id, ~text, ~votes, ~comments) => {
  <div id={id}>
    <span>{text |> Util.ste}</span>
    {switch(votes) {
    | None => "0" |> Util.ste
    | Some(votes) => <div>{"Votes:" |> Util.ste} {string_of_int(Array.length(votes)) |> Util.ste}</div>
    }}
    <Comments comments={comments} />
  </div>
};