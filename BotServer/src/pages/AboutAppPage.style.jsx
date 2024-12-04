import styled from 'styled-components';

export const AboutAppPageContainer = styled.div`
    font-family: 'Roboto', sans-serif;
    background-color: #f8f9fa;
`;

export const Content = styled.main`
    display: flex;
    justify-content: space-around;
    align-items: center;
    padding: 40px 20px;
`;

export const MobileAppInfo = styled.div`
    max-width: 45%;
    padding: 20px;
`;

export const MobileAppInfoHeading = styled.h1`
    font-size: 2rem;
    margin-bottom: 15px;
    color: #343a40;
`;

export const MobileAppInfoText = styled.p`
    font-size: 1.2rem;
    line-height: 1.6;
    color: #495057;
`;

export const MobilePreview = styled.div`
    text-align: center;
`;

export const PhoneImage = styled.img`
    width: 200px;
    height: auto;
    border-radius: 15px;
    box-shadow: 0px 8px 15px rgba(0, 0, 0, 0.2);
`;
