import React from "react";
import { AboutAppPageContainer, Content, MobileAppInfo, MobileAppInfoHeading, MobileAppInfoText } from "./AboutAppPage.style";
import mobileImage from "./res/phoneImage.png";

const AboutAppPage = () => {
  return (
    <AboutAppPageContainer>
      <Content>
        <MobileAppInfo>
          <MobileAppInfoHeading>Mobile App</MobileAppInfoHeading>
          <MobileAppInfoText>
            When you purchase a FollowBot, a mobile app is included. To access
            the full range of features and commands for your FollowBot,
            download the FollowBotApp from the app store.
          </MobileAppInfoText>
        </MobileAppInfo>
        <div>
          <img src={mobileImage}/>
        </div>
      </Content>
    </AboutAppPageContainer>
  );
};

export default AboutAppPage;

