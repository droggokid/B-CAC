import React, { useState } from 'react';
import ReactDOM from 'react-dom';
import MainMenu from './MainMenu';
import Text from './Text';
import Button from './Button';
import TextBox from './TextBox';
import GameMenu from './GameMenu';
import Leaderboard from './Leaderboard'


const App = () => {
    const [currentComponent, setCurrentComponent] = useState('Leaderboard');
  
    const handleComponentChange = (newComponent) => {
      setCurrentComponent(newComponent);
    };
  
    const renderCurrentComponent = () => {
      switch (currentComponent) {
        case 'MainMenu':
          return <MainMenu onComponentChange={handleComponentChange} />;
        case 'GameMenu':
          return <GameMenu onComponentChange={handleComponentChange} />;
        case 'Leaderboard':
        return <Leaderboard/>;
      default:
          return null;
      }
    };
  
    return <React.StrictMode>{renderCurrentComponent()}</React.StrictMode>;
  };
  
  ReactDOM.createRoot(document.getElementById('root')).render(<App />);

