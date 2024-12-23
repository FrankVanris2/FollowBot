import React from "react";
import { 
  AboutFollowBotContainer, 
  AboutFollowBotPart, 
  FollowBotImage, 
  CenterTitle 
} from "./AboutFollowBotPage.style";
import Prototype from "../res/FollowBotPrototype.png";

const AboutFollowBotPage = () => {
  return (
    <AboutFollowBotContainer>
      <AboutFollowBotPart>
        <h1>About FollowBot</h1>
          <p>
            FollowBot is a robot designed to assist individuals by carrying and
            transporting their belongings from one location to another. It
            features capabilities like mapping, following, error correction,
            path-finding, modular modifications, and much more.
          </p>
          <p>
          FollowBot is not just a device; it's your reliable companion designed to 
          transform the way you manage your belongings and navigate university campuses 
          and other public safe places. Whether you're heading to class, moving between buildings, 
          or navigating the campus grounds, FollowBot is there to lighten your load and offer a helping 
          hand. Its sleek, modern design integrates seamlessly into your daily routine, providing a 
          blend of convenience and innovation that enhances your university life and ensures your 
          belongings are secure in safe, public spaces.
          </p>
        <h1>Advanced Navigation and Intelligent Mapping</h1>
          <p>
          Equipped with advanced navigation technology, FollowBot can effortlessly map out routes and navigate 
          through complex environments. Its intelligent sensors and algorithms allow it to understand its surroundings, 
          avoid obstacles, and follow you with precision. Imagine having a device that can carry your groceries through 
          a crowded market or your books and supplies across a busy campus, all while ensuring your items are safe and 
          secure. FollowBot’s mapping capabilities ensure you always have a reliable travel companion by your side.
          </p>
      </AboutFollowBotPart>

      <AboutFollowBotPart>
        <CenterTitle>FollowBot</CenterTitle>
          <FollowBotImage src={Prototype} alt="FollowBot Prototype"/>
          <p>
            FollowBot is a device that consists of many capabilities. Such as mapping, 
            following, carrying, error correctioning, path-finding, modular modifications, 
            and a ton more.
          </p>
      </AboutFollowBotPart>

      <AboutFollowBotPart>  
        <h1>Why is FollowBot Useful?</h1>
          <p>
            FollowBot is designed to help individuals who are unable to carry
            their belongings due to various reasons. It can be used in public
            spaces to help individuals transport their belongings safely and
            securely.
          </p>
          <p>
            When it comes to public spaces such as Universities and Big Corporate 
            campuses, FollowBot can be used to transport books, laptops, and other 
            belongings from one building to another.
          </p>
        <h1>Embracing Open Source for Innovation</h1>
          <p>
          FollowBot is proudly an open-source project, inviting collaboration and 
          innovation from developers, researchers, and tech enthusiasts around the 
          world. By sharing our source code with the public, we aim to foster a community 
          of creativity and continuous improvement. Open-source accessibility ensures transparency 
          and enables contributors to tailor FollowBot to diverse needs, enhancing its capabilities 
          and expanding its applications. Join us in this journey to create a smarter, more efficient, 
          and user-friendly FollowBot, and be a part of a global movement driving technological advancement 
          and inclusivity.
          </p>
      </AboutFollowBotPart>
      
    </AboutFollowBotContainer>
      
  );
};

export default AboutFollowBotPage;
