const element = React.createElement("div", { id: "parent" },[ [
  React.createElement("h1", { id: "red" }, "Hello world from React"),
  React.createElement("h1", {}, "again Hello world from React"),
],
[
    React.createElement("h1", {}, "Hello world from React"),
    React.createElement("h1", {}, "again Hello world from React"),
  ]
]);
const root = ReactDOM.createRoot(document.getElementById("root"));
root.render(element);
