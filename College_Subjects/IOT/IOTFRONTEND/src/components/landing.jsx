"use client"

import { useEffect, useState, useRef } from "react"
import "./style/landing.css" 
import { useNavigate } from "react-router-dom"

export default function SelectPage() {
  const [options, setOptions] = useState([])
  const [selectedOption, setSelectedOption] = useState(null)
  const [isLoading, setIsLoading] = useState(true)
  const [isOpen, setIsOpen] = useState(false)
  const dropdownRef = useRef(null)
  const navigate = useNavigate(null);

  useEffect(() => {
    const fetchOptions = async () => {
      try {
        const response = await fetch(`http://localhost:7777/unique-bed-numbers`)
        const data = await response.json()
        console.log("Response Data:", data)
    
        // Convert raw numbers to objects with id and name
        const formattedOptions = (data.bed_numbers || []).map((bed) => ({
          id: bed,
          name: bed.toString(),
        }))
     //   console.log("Formatted Options:", formattedOptions)
    
        setOptions(formattedOptions)
      } catch (error) {
      //  console.error("Error fetching options:", error)
      } finally {
        setIsLoading(false)
      }
    }
    

    fetchOptions()
  }, [])

  useEffect(() => {
    const handleClickOutside = (event) => {
      if (dropdownRef.current && !dropdownRef.current.contains(event.target)) {
        setIsOpen(false)
      }
    }

    document.addEventListener("mousedown", handleClickOutside)
    return () => {
      document.removeEventListener("mousedown", handleClickOutside)
    }
  }, [])

  const handleNext = () => {
    if (selectedOption) {
    //  console.log(selectOption)
      navigate(`/id/${selectedOption.id}`);
    } else {
      alert("Please select an option first")
    }
  }

  const toggleDropdown = () => {
    if (!isLoading) {
      setIsOpen(!isOpen)
    }
  }

  const selectOption = (option) => {
    setSelectedOption(option)
    setIsOpen(false)
  }

  return (
    <div className="container">
      <h1>Select a Bed Record</h1>

      <div className="controls">
      <select
  value={selectedOption?.id || ""}
  onChange={(e) => {
    const selectedId = e.target.value
    const option = options.find((opt) => opt.id.toString() === selectedId)
    console.log(option);
    selectOption(option)
  }}
  disabled={isLoading}
  className="dropdown-select"
>
  {isLoading ? (
    <option>Loading...</option>
  ) : (
    <>
      <option value="">Select an option</option>
      {options.map((option) => (
        <option key={option.id} value={option.id}>
          Bed number: {option.name}
        </option>
      ))}
    </>
  )}
</select>



        <button
          onClick={handleNext}
          disabled={!selectedOption || isLoading}
          className="next-button"
        >
          Next →
        </button>
      </div>

      {selectedOption && (
        <p className="selected-text">You selected: {selectedOption.name}</p>
      )}
    </div>
  )
}
