import {Link} from "react-router-dom"
export function Navbar(){
    return(
        <>
            <Link to="/" > 
                <button>Home</button>
            </Link>
            <Link to="/page1" > 
                <button>page1</button> 
            </Link> 
            <Link to="/page2" > 
                <button>page2</button>
            </Link>
            <Link to="/page3" > 
                <button>page13</button>
            </Link>
        </>
    )
}