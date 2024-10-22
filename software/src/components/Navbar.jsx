// import React from 'react'
import "../css/Navbar.css";
import file from  "../images/file.png";
function Navbar() {
  return (
   <>
   <nav>
  <input type="checkbox" id="checkbox" />
  <label htmlFor="checkbox" className="checkbtn">
    <i className="fa-solid fa-bars"></i>
  </label>
  <div className="logos">
    <img className="logo" src={file} />
    <h1 id="logo">IOT AGRITECH</h1>
  </div>
    <ul className="nav-list">
      <li className="nav-list-item"><a className="nav-link" id="home">Home</a></li>
      <li className="nav-list-item"><a className="nav-link" id="about">About</a></li>
      <li className="nav-list-item"><a className="nav-link" id="contact">Contact</a></li>
      <li className="nav-list-item"><a className="nav-link" id="signup">Sign Up</a></li>
      <li className="nav-list-item"><a className="nav-link" id="login">Login</a></li>
    </ul>
</nav>
  
   </>
   
  )
}

export default Navbar