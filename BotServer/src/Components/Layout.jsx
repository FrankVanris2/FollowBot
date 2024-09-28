import { Outlet } from "react-router-dom";
import { Navbar } from "./Navbar";

 export function Layout(){
    return(
        <>

            <Navbar/>
            {/* need to go back and check as i dont have main  */}
            <Main>
                <Outlet/>
            </Main>
        </>
    )   
 }