import React from "react";
import "../styles/AboutFollowBotPage.style.css"; // Ensure this path is correct
import Prototype from "../res/FollowBotPrototype.png";

const AboutFollowBotPage = () => {
  return (
    <div className="about-follow-bot-container">
      <div className="about-follow-bot-part">
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
          hand.
        </p>
        <h1>Advanced Navigation and Intelligent Mapping</h1>
        <p>
          Equipped with advanced navigation technology, FollowBot can effortlessly map out routes and navigate
          through complex environments. Its intelligent sensors and algorithms allow it to understand its surroundings,
          avoid obstacles, and follow you with precision.
        </p>
      </div>

      <div className="about-follow-bot-part">
        <h1 className="center-title">FollowBot</h1>
        <img className="follow-bot-image" src={Prototype} alt="FollowBot Prototype" />
        <p>
          FollowBot is a device that consists of many capabilities such as mapping,
          following, carrying, error correction, path-finding, modular modifications,
          and much more.
        </p>
      </div>

      <div className="about-follow-bot-part">
        <h1>Why is FollowBot Useful?</h1>
        <p>
          FollowBot is designed to help individuals who are unable to carry
          their belongings due to various reasons. It can be used in public
          spaces to help individuals transport their belongings safely and
          securely.
        </p>
        <p>
          When it comes to public spaces such as universities and large corporate
          campuses, FollowBot can be used to transport books, laptops, and other
          belongings from one building to another.
        </p>
        <h1>Embracing Open Source for Innovation</h1>
        <p>
          FollowBot is proudly an open-source project, inviting collaboration and
          innovation from developers, researchers, and tech enthusiasts around the
          world. By sharing our source code with the public, we aim to foster a community
          of creativity and continuous improvement.
        </p>
      </div>
    </div>
  );
};

export default AboutFollowBotPage;