#include <Arduino.h>
#include <SoftwareSerial.h>
#include <string.h>
#ifndef TESTOWY_1_CAR_MODULES_HPP
#define TESTOWY_1_CAR_MODULES_HPP

//int convert_to_int(char cmd[100]){
//    return
//};
#define INF 20000;


class BluetoothModule{
public:
    BluetoothModule(const int& rx_pin, const int& tx_pin): rx_pin_(rx_pin), tx_pin_(tx_pin), serial_bt_(SoftwareSerial(rx_pin_, tx_pin_)), device_to_change_('n'), engine_gear_('f'), engine_value_(0), servo_value_(0) { }

    void bluetooth_setup(){ serial_bt_.begin(9600); }

    void read_device_value();

    char getDeviceToChange() const;

    int available(){
        return serial_bt_.available();
    }

    int getServoValue() const;

    int getEngineValue() const;

    char getEngineGear() const;


private:
    void read_cmd();
    const int& rx_pin_;
    const int& tx_pin_;
    SoftwareSerial serial_bt_;
    char cmd_[100];
    int cmdIndex_ = 0;
    char device_to_change_; //przyjmuje 'n' jeżeli nic nie zmienia, 'e' jeżeli zmienia silnik, 's' jeżeli serwomechanizm
    char engine_gear_; //domyślnie na przód 'f' lub 'r' do tyłu
    int engine_value_;
    int servo_value_;

};


class Engine{
public:
    Engine(int control_pin, int GND_pin, int power_pin, BluetoothModule& bt): GND_pin_(GND_pin), power_pin_(power_pin), control_pin_(control_pin), bt_(bt), speed_(0){}
    //tutaj musi control pin być zwykłym int bo używamy go w dalszych funkcjach z biblioteki arduino

    void engine_setup();

    void turn(int control_pin_value=0, int power_pin_lvl = 1, int gnd_pin_lvl=0);

    virtual void setSpeed();

    int getSpeed() const {
        return speed_;
    }

protected:
    int GND_pin_;
    int power_pin_;
    int control_pin_;
    BluetoothModule& bt_; //tworzę te pola jako protected ponieważ klasy dziedziczące muszą mieć do nich dostęp - można też to zrobić jako getter ale gette powinien być const ...
    int speed_; //speed będzie zmieniany w zależności od tego co bluetooth powie za pomocą settera na początku 0

};

class ControlEngine : public Engine{
public:
    using Engine::Engine;
//    ControlEngine(int control_pin, int GND_pin, int power_pin, BluetoothModule& bt) : Engine( control_pin,  GND_pin,  power_pin, bt){}

    void setSpeed();


};

class DistanceSensor{
public:
    DistanceSensor(int trig_pin, int echo_pin): trig_pin_(trig_pin), echo_pin_(echo_pin){}

    void sensor_setup();

    void change_distance();

    int getDistance() const {
        return distance_;
    };



private:
    int trig_pin_;
    int echo_pin_;
    int distance_ = INF // to może nie działać


};

#endif //TESTOWY_1_CAR_MODULES_HPP
