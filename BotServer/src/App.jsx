import React from 'react';
import {GlobalStyle, HelloWorld, CrazyFace} from './App.style';
import CrazyFaceImg from './crazyface.png';

const App = () => (
  <>
    <GlobalStyle />

    {/* Example component (remove it when writing your own code) */}
    <HelloWorld>
      Hello, world!
      <CrazyFace src={CrazyFaceImg} />
    </HelloWorld>
  </>
);

export default App;
