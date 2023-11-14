import React, { useState } from 'react';
import ReactDOM from 'react-dom';
import MainMenu from './MainMenu';
import Text from './Text';
import Button from './Button';
import TextBox from './TextBox';
import TextBorder from './TextBorder';

import InitialsBox from './InitialsBox';



const App = () => {
  const [currentComponent, setCurrentComponent] = useState('MainMenu');

  const handleComponentChange = (newComponent) => {
    setCurrentComponent(newComponent);
  };

  const renderCurrentComponent = () => {
    switch (currentComponent) {
      case 'MainMenu':
        return <MainMenu onComponentChange={handleComponentChange} />;
      // Add more cases for other components as needed
      default:
        return null;
    }
  };

  return <React.StrictMode>{renderCurrentComponent()}</React.StrictMode>;
};

ReactDOM.createRoot(document.getElementById('root')).render(<App />);

