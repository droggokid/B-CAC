import React, { useState } from 'react';
import ReactDOM from 'react-dom/client';
import MainMenu from './MainMenu';
import GameMenu from './GameMenu';
import axios from 'axios';

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

