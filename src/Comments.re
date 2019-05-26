[@react.component]
let make = (~comments) => {
  switch(comments) {
  | None => "No comments" |> Util.ste
  | Some(comments) =>
  <div>
    <h3>{"Comments" |> Util.ste}</h3>
    <div>
      {comments |> Array.map(comment =>
        switch(comment) {
        | None => "None" |> Util.ste
        | Some(comment) => {
          <Comment
            key={comment##id}
            id={comment##id}
            text={comment##text}
            author={comment##author}
          />
        }
        }
      ) |> React.array}
    </div>
  </div>
  }
};
