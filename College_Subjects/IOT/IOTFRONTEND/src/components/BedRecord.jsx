"use client";

import { useEffect, useState } from "react";
import { useParams } from "react-router-dom";

export default function BedRecordsViewer() {
  const [records, setRecords] = useState([]);
  const {bedId}= useParams(); 
  
  // URL of initial fetch
  
  const initialFetchUrl = "http://localhost:7777/bed-records?bed_id=" + bedId;
  
  // URL of periodic fetch
  const periodicFetchUrl = "http://localhost:7777/latest-bed-record?bed_id="+ bedId;

  useEffect(() => {
    const fetchInitialRecords = async () => {
      try {
        const response = await fetch(initialFetchUrl);
        const data = await response.json();
       // console.log(data)
        setRecords(data.records || []);
      } catch (error) {
        console.error("Error fetching initial records:", error);
      }
    };

    fetchInitialRecords();

    // Set interval for periodic fetch
    const intervalId = setInterval(async () => {
      try {
        const response = await fetch(periodicFetchUrl);
        const data = await response.json();
       
        if (data.record) {
          console.log(data.record)  
          setRecords((prevRecords) => [...prevRecords, data.record]);
          console.log(records);
        }
      } catch (error) {
        console.error("Error fetching periodic records:", error);
      }
      
    }, 5000); // fetch every 5 seconds

    // Clear interval when component unmounts
    return () => clearInterval(intervalId);
  }, []);
  return (
    <div style={{ padding: "20px" ,backgroundColor:"black",width:"50%",margin:"auto",height:"90vh",overflowY:"scroll"}}>
      <h1 style={{textAlign:"center"}}>Bed Records Viewer</h1>
      <table style={{ width: "100%", borderCollapse: "collapse" }}>
        <thead>
          <tr>
            <th style={{ border: "1px solid black", padding: "8px",textAlign:"start" }}>Timestamp</th>
            <th style={{ border: "1px solid black", padding: "8px" }}>Saline</th>
          </tr>
        </thead>
        <tbody>
          {records.map((record) => (
            <tr key={record.id}>
              <td style={{ border: "1px solid black", padding: "8px"}}>
                {new Date(record.timestamp).toLocaleString()}
              </td>
              <td style={{ border: "1px solid black", padding: "8px",textAlign:"center" }}>{record.saline}</td> 
            </tr>
          ))}
        </tbody>
      </table>
    </div>
  );
}
