
#ifndef TESTOWY_1_CAR_HPP
#define TESTOWY_1_CAR_HPP

#include "car_modules.hpp"


class Car{
public:
    Car(BluetoothModule& bt, Engine& en, ControlEngine& c_en, DistanceSensor& ds): bt_(bt), en_(en),c_en_(c_en), ds_(ds) {}

    void setup();

    bool is_connected(){
        return bt_.available() > 0;
    }

    void drive();
private:
    BluetoothModule& bt_;
    Engine& en_;
    ControlEngine& c_en_;
    DistanceSensor& ds_;
};

#endif //TESTOWY_1_CAR_HPP
