# Projekt samochodu 
Opis projektu:
Idea projektu narodziła się we wrześniu 2021 roku. Głównym celem było stworzenie samochodu, sterowanego przez bluetooth za pomocą Arduino. 
Cele poboczne: Projekty w C++, lutowanie i inne przydatne umiejętności.

Cele i zamierzenia:
1. Poznanie podstaw elektroniki poprzez Stworzenie samochodziku z wykorzystaniem części ze starej zabawki.
2. Nauka tworzenia projektów w języku Cpp poprzez tworzenie projektu Clion oraz programowanie obiektowe.
3. Zdobycie wiedzy na temat cyfrowych czujników i komponentów poprzez zastosowanie np. modułu Bluetooth, czujnika odległości.

Krok po kroku (działania):

1. stworzenie listy niezbędnych komponentów takich jak:
Mikrokontroler, mostek H, modul bluetooth, bateria, kable, płytka stykowa, kabel od baterii do arduino, czujnik odległości,
mały silnik (do sterowania lewą, prawą pozycją), silnik o większej mocy do sterowania prędkością samochodu.
Akumulator lub powerbank (im bardziej nieważki tym lepiej), kabel USB b, 4 kółka, 4 sprężyny, 

1 podwozie.
Multimetr, rezystory, konwerter 5 -> 3. 3V

2. Naprawa niezbędnych elementów:
1. Powerbank poprzez dodanie 2 przewodów + i -
2. Silniki poprzez lutowanie przewodów z nowymi przewodami.
3. Kupowanie komponentów, które nie są nabyte (att_1)

4. Zapoznanie się z silnikiem z "Kurs Arduino", stworzenie niezbędnego połączenia pomiędzy płytką Arduino, Powerbankiem, płytką stykową i silnikiem (att_2)
att_2 przedstawia ideę podłączenia przewodów do Arduino. W naszym projekcie jest to trochę zmienione
ponieważ moc baterii 9v nie wystarcza na 2 silniki.
Zamiast nich łączę zewnętrzny powerbank z płytki stykowej do pozycji +/- i z +/- do vcc
w układzie H-bridge


5. Tworzenie dokumentacji i architektury klas:
Zdecydowałem się na stworzenie mojego projektu w Clionie ze względu na jego łatwą naturę w programowaniu obiektowym.

6. Przewody Arduino:

* PIN:
3 en_control_pin : niebieski
4 GND_pin : biały
5 PowerPin : żółty
6 odległośćEcho czujnika : fioletowy
7 dS trig : pomarańczowy + niebieski
8 bt RX: zielony
9 bt TX: szary
10 -
11: cen control_pin: czerwony
12: styk GND: żółty
13: power_pin: brąz
5V: strona + : fioletowy
GND - strona przeciwna: pomarańczowy

GND : fioletowy BT

7. Kontrolowanie odległości samochodu od obiektów z wykorzystaniem odpowiedniego czujnika. 
 1. Głównym celem tego zadania jest wyznaczenie pozycji od np. ściany i doprowadzenie samochodu do przejechania dokładnej odległości.
 2. Brak czujnika prędkości.

    Zamierzenia:

    1. Identfikacja transmitancji:
    2. zbieranie danych - w celu zbierania danych należy sporządzić bazę danych z odległością samochodu od ściany (czas + mierzona odległość)
    3. wykonać skrypt w Matlabie
    4.. analiza różnic pomiędzy różnymi typami K - (const friction)




# CarProject

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

    
    
