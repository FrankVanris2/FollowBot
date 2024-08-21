import styled, {createGlobalStyle} from 'styled-components';

export const GlobalStyle = createGlobalStyle`
  body {
    font-family: Arial;
    font-size: 14px;
    overflow: auto;
  }
`;

// Example style (remove it when writing your own code)
export const HelloWorld = styled.div`
  display: flex;
  justify-content: center;
  align-items: center;
  width: 200px;
  height: 150px;
  margin: 20px;
  color: lightBlue;
  font-weight: bolder;
  background: linear-gradient(0.1turn, red, green);
`;

export const CrazyFace = styled.img`
  margin-left: 20px;
  width: 20px;
  height: 20px;
`;
