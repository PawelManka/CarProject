#include <SoftwareSerial.h>// import the serial library
#include <Arduino.h>
#include <car.hpp>

BluetoothModule bt(9,8);
Engine en(3,4,5,bt);
ControlEngine c_en(11, 12, 13, bt);
DistanceSensor ds(7,6);
Car car(bt, en, c_en, ds);


void setup()
{
    car.setup();
    Serial.begin(9600);

}


void loop() {

    if(car.is_connected()){ //za każdym razem w pliku wykonawczym musimy to robić po potem działa jak nie ma działa :(

//        Serial.print(bt.getDeviceToChange());
//        Serial.println(bt.getEngineValue());
//        en.setSpeed(speed); //ustawiam prędkość w zależności od

//
//        Serial.println(en.getSpeed());
//        analogWrite(3, en.getSpeed());
//        Serial.println(c_en.getSpeed());

        car.drive();


    }

//    ds.change_distance();
//    Serial.print(ds.getDistance());
//    Serial.println(" cm");
//    delay(500); //obsuwa żeby nie printowało jak głupi

}