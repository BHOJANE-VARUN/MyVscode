import { BrowserRouter as Router, Routes, Route } from "react-router-dom";
import SelectPage from "./components/landing";
import BedRecordsViewer from "./components/BedRecord";
import SalineStatus from "./components/SalineStatus";

function App() {
  return (
    <Router>
      <Routes>
        <Route path="/" element={<SelectPage />} />
        <Route path="/id/:bedId" element={<SalineStatus />} />
      </Routes>
    </Router>
  );
}

export default App;
