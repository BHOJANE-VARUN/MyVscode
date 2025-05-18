import React, { useEffect, useState } from 'react';
import { useParams } from 'react-router-dom';

const SalineStatus = () => {
  const { bedId } = useParams();
  const bedNumber = bedId; // Extracting the bed number from the ID
  const [status, setStatus] = useState(null);
  const [error, setError] = useState(null);

  const fetchStatus = async () => {
    try {
      const res = await fetch(`http://localhost:7777/saline-status?bed_id=${bedNumber}`);
      const data = await res.json();

      if (!res.ok) {
        throw new Error(data.error || 'Unknown error');
      }

      setStatus(data);
      setError(null);
    } catch (err) {
      setError(err.message);
      setStatus(null);
    }
  };

  useEffect(() => {
    if (bedNumber) {
      fetchStatus();
      const interval = setInterval(fetchStatus, 4000);
      return () => clearInterval(interval);
    }
  }, [bedNumber]);

  const formatDuration = (seconds) => {
    const hrs = Math.floor(seconds / 3600);
    const mins = Math.floor((seconds % 3600) / 60);
    const secs = seconds % 60;
    return `${hrs}h ${mins}m ${secs}s`;
  };

  return (
    <>
      <div className="saline-card">
        <div className="saline-header">
          <div>
            <h3 className="saline-title">Bed #{bedNumber}</h3>
            <p className="saline-subtitle">John Doe</p>
          </div>
          <div
            className={`saline-status ${
              status?.current_status === 'ON' ? 'status-off' : 'status-on'
            }`}
          >
            {status?.current_status=='ON'?"OFF":"ON"}
          </div>
        </div>

        {error ? (
          <p className="saline-error">{error}</p>
        ) : status ? (
          <div className="saline-body">
            <div>
              <span className="saline-label">Since</span>
              <div>{new Date(status.since).toLocaleTimeString([], { hour: '2-digit', minute: '2-digit' })}</div>
            </div>
            <div>
              <span className="saline-label">Lelay</span>
              <div>{formatDuration(status.duration_in_current_state_seconds)}</div>
            </div>
          </div>
        ) : (
          <p className="saline-loading">Loading...</p>
        )}

        <button className="saline-button">View Details</button>
      </div>

      <style>{`
        .saline-card {
          background: white;
          border-radius: 12px;
          box-shadow: 0 4px 10px rgba(0, 0, 0, 0.1);
          padding: 16px;
          max-width: 320px;
          margin: 24px auto;
          font-family: Arial, sans-serif;
        }

        .saline-header {
          display: flex;
          justify-content: space-between;
          align-items: center;
        }

        .saline-title {
          font-size: 18px;
          font-weight: bold;
          margin: 0;
        }

        .saline-subtitle {
          font-size: 14px;
          color: #666;
          margin-top: 2px;
        }

        .saline-status {
          padding: 4px 10px;
          font-size: 14px;
          font-weight: bold;
          border-radius: 999px;
        }

        .status-on {
          background-color: #d1fadc;
          color: #0f9d58;
        }

        .status-off {
          background-color: #ffe4e4;
          color: #d93025;
        }

        .saline-body {
          margin-top: 16px;
          font-size: 14px;
          color: #333;
        }

        .saline-label {
          font-weight: bold;
          display: block;
        }

        .saline-button {
          margin-top: 20px;
          background-color: #2563eb;
          color: white;
          padding: 10px;
          width: 100%;
          border: none;
          border-radius: 6px;
          font-size: 14px;
          cursor: pointer;
        }

        .saline-button:hover {
          background-color: #1d4ed8;
        }

        .saline-error {
          color: red;
          margin-top: 16px;
          font-size: 14px;
        }

        .saline-loading {
          margin-top: 16px;
          color: #888;
          font-size: 14px;
        }
      `}</style>
    </>
  );
};

export default SalineStatus;
