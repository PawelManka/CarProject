# testowy_1

Project description:
The idea of the project was born in September 2021. The main goal was to create a car, controlled by bluetooth using Arduino. Additionally it helped to understand/learn the Arduino
C++ projects, soldering and other helpful skills. 

Goals and Intentions:
1. Learning basic of electronic via Creating a toy car using parts from old toy.
2. Learning Cpp project development via creating a Clion project and object oriented programming.
3. Acquired knowledge of digital sensors and components throug using f.e Bluetooth module, distant sensor.

Step by step (actions):
1. creating list of necessery components such as:
    Microcontoller, H-bridge, bluetooth modul, battery, cables, small breadbord, battery to arduino cable, distant sensor, 
    small engine (to control left, right position), engine with bigger power to control car speed. 
    Accumulator or powerbank (the more weightless the better), USB b cablem, 4 wheels, 4 spring, 1 under carriage.
    Multimeter, Resistors, 5 -> 3.3V converter
    
2. Repairing necessery components:
    1. Powerbank by adding 2 wires + and -
    2. Engines by soldering wires with new wires.
3. Buying components that arent acquired. (att_1)

4. Learning about the engine from "Kurs Arduino", making necessery link between Arduino Board, Powerbank, BreadBoard and Engine. (att_2)
    att_2 depict the idea of linking wires into Arduino. In our Project it is a little bit changed
    because of the fact that 9v battery power is not enough for 2 engines.
    Instead of these I link outer powerbank to BreadBord to +/- position and from +/- to vcc
    in H-bridge scheme
    
5. Making documentation and class architecture:
    I decide to create my project in Clion because of its easy nature in object oriented programming. 
    After s
6. Arduino wires: 

    * PIN:
    3 en_control_pin : blue
    4 GND_pin : white 
    5 PowerPin : yellow
    6 distanceSensor echo : purple
    7 dS trig : orange + blue
    8 bt RX: green
    9 bt TX: grey
    10 -
    11: cen control_pin: red
    12: GND pin: yellow 
    13: power_pin: bronze 
    5V: + side : Purple
    GND - opposit site -: orange
    
    GND : purple BT
    
7. Control distance in car. - Main goal of this task is to set position from f.e. wall and make car to drive to exact distance.
    Minus of the situation is that there is no angular velocity sensor.
   
   Intensions:
   
   1. Identification Transmitation:
       1. collect data - to collect data it should be made a list in distant sensor object that acquire time and measured distance.
       2. make script in Matlab 
   2. analis diffrence between different type of K - (const friction) 
   3. 
    
    