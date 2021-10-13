#include <car.hpp>


void Car::setup() {
    bt_.bluetooth_setup();
    en_.engine_setup();
    c_en_.engine_setup();
    ds_.sensor_setup();

}

void Car::drive() {

    bt_.read_device_value();
    en_.setSpeed(); //silniki mają jako pola bluetoothy!
    c_en_.setSpeed();

}
