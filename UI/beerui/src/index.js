import React, { useState } from 'react';
import ReactDOM from 'react-dom';
import MainMenu from './MainMenu';
import Text from './Text';
import Button from './Button';
import TextBox from './TextBox';
import GameMenu from './GameMenu';


const App = () => {
    const [currentComponent, setCurrentComponent] = useState('MainMenu');
  
    const handleComponentChange = (newComponent) => {
      setCurrentComponent(newComponent);
    };
  
    const renderCurrentComponent = () => {
      switch (currentComponent) {
        case 'MainMenu':
          return <MainMenu onComponentChange={handleComponentChange} />;
        case 'GameMenu':
          return <GameMenu onComponentChange={handleComponentChange} />;
        default:
          return null;
      }
    };
  
    return <React.StrictMode>{renderCurrentComponent()}</React.StrictMode>;
  };
  
  ReactDOM.createRoot(document.getElementById('root')).render(<App />);

