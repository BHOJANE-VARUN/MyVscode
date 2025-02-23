import React from "react";

const Card = ({id,name,department}) => {
  return <tr>
        <td>{id}</td>
        <td>{name}</td>
        <td>{department}</td>
  </tr>;
};
export default Card;
