# Air Conditioner App (based on C++&QtWidget)
The project developed a graphical user interface, oriented towards work on a touch screen and intended for control and monitoring of the air conditioning system.
![main-photo](Image/main.png)

## The application displays the following information:
- Temperature | degrees (the possibility of Celsius, Fahrenheit, Kelvin scales is provided using finite state machines);
- Humidity | %;
- Pressure | Pa
(note: recalculation of temperature and pressure values ​​is provided depending on the settings selected by the operator)
## The composition of the application's controls:
- Air conditioning on/off control;
- Temperature control;
- Air flow direction control (just described in debug);
## The app also includes:
- Simulation of input parameters coming from the air conditioning system (temperature, pressure, humidity), implemented as an input in a separate window of values;
- User settings (temperature display scale, pressure, humidity and theme) are saved in an XML file and loaded at the next startup;
- Implemented 2 interface design styles: light and dark variants

## Result:
![gif](Image/m.gif)
