[@react.component]
let make = (~label, ~type_, ~onChange) => {
  <div>
    <label> {Util.ste(label)} </label>
    <input
      type_={type_}
      placeholder={label}
      onChange={onChange}
    />
  </div>
};