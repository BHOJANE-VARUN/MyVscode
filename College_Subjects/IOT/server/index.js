const express = require("express");
const { getAsyncConnection } = require("./util/database.js");
const app = express();
const port = 7777;
var asyncDBconnection;
app.use(express.json());

app.get('/saline-status', async (req, res) => {
  const bedNumber = req.query.bed_id;
  if (!bedNumber) {
    return res.status(400).json({ error: "Missing bed_number query parameter" });
  }

  try {
    const [rows] = await asyncDBconnection.execute(
      `SELECT * FROM records 
       WHERE bed_number = ? 
       ORDER BY timestamp DESC 
       LIMIT 10`, 
       [bedNumber]
    );

    if (rows.length === 0) {
      return res.status(404).json({ message: "No data found for given bed number" });
    }

    const currentState = rows[0].saline;
    const startTime = new Date(rows[0].timestamp);
    let endTime = startTime;

    for (let i = 1; i < rows.length; i++) {
      if (rows[i].saline === currentState) {
        endTime = new Date(rows[i].timestamp);
      } else {
        break;
      }
    }

    const durationSeconds = Math.floor((startTime - endTime) / 1000);

    res.json({
      bed_number: bedNumber,
      current_status: currentState === 0 ? "ON" : "OFF",
      since: endTime.toISOString(),
      duration_in_current_state_seconds: durationSeconds
    });

  } catch (err) {
    console.error(err);
    res.status(500).json({ error: "Internal Server Error" });
  }
});






app.post("/add-bed", async (req, res) => {
  try {
    console.log(req.body);
    const { bed_number, saline } = req.body;
    const query = `
            INSERT INTO records (bed_number, saline)
            VALUES (?, ?)
        `;

    const [results] = await asyncDBconnection.query(query, [
      bed_number,
      saline,
    ]);

    res
      .status(201)
      .json({ message: "Data inserted successfully", id: results.insertId });
  } catch (error) {
    console.error("Error inserting data:", error);
    res.status(500).json({ error: "Database error" });
  }
});

app.get("/bed-records", async (req, res) => {
  try {
    const bed_id = req.query.bed_id;

    if (!bed_id) {
      return res
        .status(400)
        .json({ error: "bed_id query parameter is required" });
    }

    const query = `
            SELECT * 
            FROM records 
            WHERE bed_number = ? 
            AND timestamp >= NOW() - INTERVAL 1 DAY 
            ORDER BY timestamp DESC 
            LIMIT 5;
        `;

    const [rows] = await asyncDBconnection.query(query, [bed_id]);

    res.status(200).json({ records: rows });
  } catch (error) {
    console.error("Error fetching data:", error);
    res.status(500).json({ error: "Database error" });
  }
});

app.get("/latest-bed-record", async (req, res) => {
    try {
      const bed_id = req.query.bed_id;
  
      if (!bed_id) {
        return res
          .status(400)
          .json({ error: "bed_id query parameter is required" });
      }
  
      const query = `
        SELECT * 
        FROM records 
        WHERE bed_number = ? 
        ORDER BY timestamp DESC 
        LIMIT 1;
      `;
  
      const [rows] = await asyncDBconnection.query(query, [bed_id]);
  
      res.status(200).json({ record: rows[0] || null });
    } catch (error) {
      console.error("Error fetching latest record:", error);
      res.status(500).json({ error: "Database error" });
    }
});
  

app.get("/unique-bed-numbers", async (req, res) => {
  try {
    const query = `
          SELECT DISTINCT bed_number 
          FROM records
          ORDER BY bed_number ASC
      `;

    const [rows] = await asyncDBconnection.query(query);

    const bedNumbers = rows.map((row) => row.bed_number);

    res.status(200).json({ bed_numbers: bedNumbers });
  } catch (error) {
    console.error("Error fetching unique bed numbers:", error);
    res.status(500).json({ error: "Database error" });
  }
});

getAsyncConnection()
  .then((result) => {
    console.log("async Connected!");
    asyncDBconnection = result;
    app.listen(port, () => {
      console.log("app is listening on port no", port);
    });
  })
  .catch((err) => {
    console.error(err);
  });
