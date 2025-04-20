import styled from 'styled-components';

export const Header = styled.header`
  display: flex;
  align-items: center;
  justify-content: center;
  padding: 10px 20px;
  background-color: #007bff; /* Header background color */
  color: white; /* Text color */
  font-size: 1.5rem;
  font-weight: bold;

  img {
    height: 50px; /* Adjust logo size */
    margin-right: 10px;
  }

  .title {
    font-size: 1.5rem;
  }

  @media (max-width: 768px) {
    flex-direction: column;
    text-align: center;

    img {
      margin-bottom: 10px;
    }
  }
`;

export const Nav = styled.nav`
  display: flex;
  justify-content: space-between;
  align-items: center;
  padding: 10px 20px;
  background-color: #333; /* Navbar background color */
  color: white; /* Text color */

  .site-title {
    font-size: 1.5rem;
    font-weight: bold;
    color: white;
    text-decoration: none;
  }

  @media (max-width: 768px) {
    flex-direction: column;
    align-items: flex-start;

    .site-title {
      margin-bottom: 10px;
    }
  }
`;

export const NavList = styled.ul`
  display: flex;
  list-style: none;
  margin: 0;
  padding: 0;
  gap: 20px; /* Space between navbar items */

  @media (max-width: 768px) {
    flex-direction: column;
    gap: 10px;
    width: 100%;
  }
`;

export const LinkItem = styled.li`
  a {
    color: white;
    text-decoration: none;
    font-size: 1rem;
    padding: 10px 15px;
    transition: background-color 0.3s ease;

    &:hover {
      background-color: rgba(255, 255, 255, 0.1); /* Hover effect */
      border-radius: 5px;
    }

    &.active {
      background-color: rgba(255, 255, 255, 0.2); /* Active link effect */
      border-radius: 5px;
    }
  }

  @media (max-width: 768px) {
    width: 100%;

    a {
      width: 100%;
      text-align: left;
    }
  }
`;