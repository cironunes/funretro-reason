[@react.component]
let make = (~id, ~text, ~author) => {
  <li id={id} key={id}>
    <div>{text |> Util.ste}</div>
    <div>{author##firstName |> Util.ste} {author##lastName |> Util.ste}</div>
  </li>
};
