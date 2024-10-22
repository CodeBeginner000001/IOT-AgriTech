// import React from 'react'
import insta from "../images/insta.png";
import footerTree from "../images/footerTree.png";
import file from "../images/file.png";
import "../css/Footer.css";
function Footer() {
  return (
   <>
   <footer className="footer">
    <div className="f-container">     
        <div className="fcont" id="c">
            <img className="f-img" src={file} />
            <h1 className="f-logo">IOT AGRITECH</h1>
            <h1 className="f-socials">Social Networks</h1>
            <div className="f-items">
                <div className="insta f-box"><img className="f-socials-img" src={insta} /></div>
                <div className="twitter f-box"></div>
                <div className="facebook f-box"></div>
            </div>
        </div>
        <div className="fcont jp" id="Navigation">
           <h1 className="f-title">Navigation</h1>
           <ul className="f-list">
            <li className="f-list-item">Home</li>
            <li className="f-list-item">About</li>
            <li className="f-list-item">Contact</li>
           </ul>
        </div>
        <div className="fcont jp" id="About">
            <h1 className="f-title" id="about">About Us</h1>
            <ul className="f-list">
             <li className="f-list-item">FAQ</li>
             <li className="f-list-item">Contact Us</li>
            </ul>
        </div>
        <div className="fcont jp">
            <h1 className="f-title">Account</h1>
            <ul className="f-list">
             <li className="f-list-item">Sign Up</li>
             <li className="f-list-item">Login</li>
            </ul>
        </div>
        <div className="rectangle-parent8">
            <img
              className="tree-removebg-preview-2-icon fcont"
              loading="lazy"
              alt=""
              src={footerTree}
            /> 
        </div>
    </div>
 
</footer>
   </>
  )
}

export default Footer