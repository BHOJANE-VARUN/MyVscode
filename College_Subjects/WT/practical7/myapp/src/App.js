
import './App.css';
import Card from "./components/Card.js"




function App() {
  return (
    <table className="App">

      <tr><th>Sr.No</th><th>Name</th><th>Location</th></tr>
        <Card id={1} name={"gizzy"} department={"rainforest"} />
        <Card id={2} name={"icey"} department={"north pole"} />
        <Card id={3} name={"panda"} department={"east asia"} />
    </table>
  );
}

export default App;
