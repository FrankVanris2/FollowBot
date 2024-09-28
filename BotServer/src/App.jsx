import './App.css'
import  {hashRouter as Routes,Route} from 'react-router-dom'
import {Home, home} from './Pages/home'
import {page1} from './Pages/page1'
import {page2} from './Pages/page2'
import {page3} from './Pages/page3'
import { Layout } from './Components/Layout'
function App(){

  return(
    <Router>
      <Routes>
          <Route element={<Layout/>}>
            <Route path="/" element={Home}/>
            <Route path="/page1" element={page1}/>
            <Route path="/page2" element={page2}/>
            <Route path="/page3" element={page3}/>
          </Route>
      </Routes>
    </Router>
  )

}
export default App

