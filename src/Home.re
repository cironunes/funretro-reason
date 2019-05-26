let ste = ReasonReact.string;

let goTo = (event, route) => {
  ReactEvent.Mouse.preventDefault(event);
  ReasonReactRouter.push(route);
};

[@react.component]
let make = () =>
  <div>
    <h1> {ste("Welcome to Ansarada's fun retro")} </h1>
    <a href="/login" onClick={e => goTo(e, "login")}> {ste("Login")} </a>
    <br />
    <span> {ste("or")} </span>
    <br />
    <a href="/register" onClick={e => goTo(e, "register")}>
      {ste("Create an account")}
    </a>
  </div>;