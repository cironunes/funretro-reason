[@react.component]
let make = () => {
  let url = ReasonReactRouter.useUrl();
  Js.log(url.path);

  switch (url.path) {
  | ["login"] => <Login />
  | ["register"] => <Register />
  | ["dashboard"] => <Dashboard />
  | [] => <Home />
  | ["board", id] => <Board id={id} />
  | _ => <NotFound />
  };
};
