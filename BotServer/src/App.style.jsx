import styled, { createGlobalStyle } from 'styled-components';

export const GlobalStyle = createGlobalStyle`

@font-face {
font-family: Roboto-Regular;
src: url('../fonts/Roboto-Regular.ttf') format('truetype'); //Ensure the path is correct
font-weight: normal;
font-style: normal;
}


body {
  font-family: Roboto-Regular;
  font-size: 14px;
  overflow: auto;
}



  
`;


