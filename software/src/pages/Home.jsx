import "../css/Home.css";
import htree from "../images/htree.png";
import img from "../images/img.png";
import st from "../images/1st.png";
import nd from "../images/2nd.png";
import rd from "../images/3rd.png";
import hcont3 from "../images/hcont3.png";
import himg1 from "../images/himg1.png";
import star from "../images/star.png";
import adarsh from "../images/adarsh.png";
import sneha from "../images/sneha.png";
import { useEffect } from "react";
function Home() {
  useEffect(() => {
    // Dynamically load the Typed.js library
    const script = document.createElement('script');
    script.src = "https://unpkg.com/typed.js@2.0.16/dist/typed.umd.js";
    script.onload = () => {
      // Initialize Typed.js once the script is loaded
      var typed = new window.Typed('#element', {
        strings: [
          'Gardening is a way to a <span style="color:green">healthy life</span>',
          'Gardening: where <span style="color:green">health takes root.</span>',
          'In the garden, <span style="color:green">health blossoms.</span>',
          'Nourish your body, <span style="color:green">nurture your garden.</span>',
        ], 
        typeSpeed: 50,
      });
      console.log(typed);
    };
    
    document.body.appendChild(script);

    // Cleanup function to remove script when component unmounts
    return () => {
      document.body.removeChild(script);
    };
  }, []);
  return (
    
        <div className="container">
        <div className="hcont1 ab">       
            <div className="hcont1a a">
                <span id="element" className="gardening"></span>
                {/* <!-- <h1 className="gardening">Gardening is a way to a</h1> <span className="healthy" > healthy life.</span> --> */}
                <span className="we">
                    We help realize your dreams in making garden, let&apos;s start with small things that can change the world, so you can enjoy the fresh air forever
                </span>
                <button className="hbtn">Get Started</button>
            </div>
            <div className="hcont1b aa">
                <img className="himg" src={img} />
            </div>
        </div>
        <div className="hcont1 hcont2 c">  
            <div className="hcont1b bb hcont2a">
                <img className="himg1" src={htree} />
            </div>     
            <div className=" hcont2b">
                <h1 className="how">How We Work</h1>
                <div className="hcont1aa">
                    <div className="hcont1aaa">
                         <div className="hbox"><img className="hcontimg" src={st} /></div>
                         <p className="htext">24/7 Plant Monitoring</p>
                    </div>
                    <div className="hcont1aaa">
                        <div className="hbox"><img className="hcontimg" src={nd} /></div>
                        <p className="htext">Testing in Real World Environment</p>
                   </div>
                   <div className="hcont1aaa">
                    <div className="hbox"><img className="hcontimg" src={rd} /></div>
                    <p className="htext">Research & Analysis for Plant Dataset</p>
               </div>
                </div>
            </div>        
        </div>
        <img src={himg1} alt="" className="himga" />
        <div id="carouselExampleIndicators" className="carousel slide">
            <div className="carousel-indicators">
              <button type="button" data-bs-target="#carouselExampleIndicators" data-bs-slide-to="0" className="m1 active bg-success" aria-current="true" aria-label="Slide 1"></button>
              <button type="button" data-bs-target="#carouselExampleIndicators" data-bs-slide-to="1" className="m1 active bg-success"  aria-label="Slide 2"></button>
              <button type="button" data-bs-target="#carouselExampleIndicators" data-bs-slide-to="2" className="m1 active bg-success"  aria-label="Slide 3"></button>
            </div>
            <div className="carousel-inner">
              <div className="carousel-item active">
                <div className="hcont3">
                    <div className="hcont3a">
                        <img className="pro" src={hcont3} />
                        <h1 className="sudesh">
                         Sudesh Pahal
                        </h1>
                        <p style={{ fontStyle: "italic", fontSize: "20px" }}> </p>
                    </div>
                    <div className="hcont3b">
                        <p className="quote">&quot;</p>
                        <div className="stars"><img className="star" src={star} /><img className="star" src={star} /><img className="star" src={star} /><img className="star" src={star} /><img className="star" src={star} /></div>
                        <p className="hcont3bpara">I am overwhelmed by the prospect of integrating IoT technology into the farms. However, IOT Agritech&apos;s platform made the transition seamless and straightforward.Their innovative solutions have not only improved the efficiency of the farms but have also significantly increased my yields while reducing resource waste.</p>
                    </div>
                </div>
              </div>
              <div className="carousel-item">
                <div className="hcont3">
                    <div className="hcont3a">
                        <img className="pro" src={hcont3} />
                        <h1 className="sudesh">
                         Sudesh Pahal
                        </h1>
                        <p style={{fontStyle: "italic", fontSize: "20px"}}>Professor</p>
                    </div>
                    <div className="hcont3b">
                        <p className="quote">&quot;</p>
                        <div className="stars"><img className="star" src={star} /><img className="star" src={star} /><img className="star" src={star} /><img className="star" src={star} /><img className="star" src={star} /></div>
                        <p className="hcont3bpara">I am overwhelmed by the prospect of integrating IoT technology into the farms. However, IOT Agritech&apos;s platform made the transition seamless and straightforward.Their innovative solutions have not only improved the efficiency of the farms but have also significantly increased my yields while reducing resource waste.</p>
                    </div>
                </div>
              </div>
              <div className="carousel-item">
                <div className="hcont3">
                    <div className="hcont3a">
                        <img className="pro" src={hcont3} />
                        <h1 className="sudesh">
                         Sudesh Pahal
                        </h1>
                        <p style={{fontStyle: "italic", fontSize: "20px"}}>Professor</p>
                    </div>
                    <div className="hcont3b">
                        <p className="quote">&quot;</p>
                        <div className="stars"><img className="star" src={star} /><img className="star" src={star} /><img className="star" src={star} /><img className="star" src={star} /><img className="star" src={star} /></div>
                        <p className="hcont3bpara">I am overwhelmed by the prospect of integrating IoT technology into the farms. However, IOT Agritech&apos;s platform made the transition seamless and straightforward.Their innovative solutions have not only improved the efficiency of the farms but have also significantly increased my yields while reducing resource waste.</p>
                    </div>
                </div>
              </div>
            </div>
            <button className="carousel-control-prev" type="button" data-bs-target="#carouselExampleIndicators" data-bs-slide="prev">
              <span className="carousel-control-prev-icon" aria-hidden="true"></span>
              <span className="visually-hidden">Previous</span>
            </button>
            <button className="carousel-control-next" type="button" data-bs-target="#carouselExampleIndicators" data-bs-slide="next">
              <span className="carousel-control-next-icon" aria-hidden="true"></span>
              <span className="visually-hidden">Next</span>
            </button>
          </div>
          <div className="sample">
        <div className="hcont4">
            <div className="hcont4a">
                <h1 className="team">Our Team</h1>
                <p className="teampara">Our team <span style={{color:"#178D04"}}>IOT AGRITECH </span>dedicatedly aims to expertise in agriculture and technology to revolutionize farming practices. We&apos;re committed to empowering farmers with innovative IoT solutions for greater efficiency, sustainability, and success.</p>
            </div>
            <div className="hcont4b">
                <div className="hcont4ba dd">
                    <img className="pro stu" src={adarsh} />
                    <h1 className="sudesh">
                   Adarsh Goyal
                    </h1>
                    <p className="founder">FOUNDER</p>
                    <p className="cont4para">As the visionary founder of IOT AGRITECH, Adarsh Goyal brings a unique blend of passion, expertise, and innovation to the table and has spearheaded the development of groundbreaking IoT solutions tailored to the needs of modern farmers.</p>
                </div>
                <div className="hcont4ba cc">
                    <img className="pro stu" src={sneha} />
                    <h1 className="sudesh">Sneha Gupta</h1>
                    <p className="founder">C0-FOUNDER</p>
                    <p className="cont4para">As the co-founder of IOT AGRITECH, Sneha Gupta brings invaluable expertise and a shared vision for innovation in agriculture and  complements the team with their strategic insights and technical prowess.</p>
                </div>
            </div>
        </div>
          </div>
    </div>
  
  
  )
}

export default Home