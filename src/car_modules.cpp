#include <car_modules.hpp>

void BluetoothModule::read_cmd() {

    while(serial_bt_.available() > 0) //tutaj pyta się programu bluetooth czy coś jest w serialu jeżeli tak to wchodzi do ifa
    {
        char c = (char)serial_bt_.read(); //czyta znak char
        if (c == '\n') { //aplikacja kiedy kończy wysyłanie robi wysyła znak nowej lini wtedy
            cmd_[cmdIndex_] = 0; //tutaj przyrównuje ostatni do 0 jako koniec zapisu trochę dziwne ale czasem siętak robi wg języka C xDDD
            cmdIndex_ = 0;
        } else {
            cmd_[cmdIndex_] = c;
            if (cmdIndex_ < 99) cmdIndex_++;
        }
    }
}

void BluetoothModule::read_device_value() {

    read_cmd();
    if(cmd_[0] == 's'){
        device_to_change_ = 's';
        servo_value_ = atoi(cmd_ + 2);
    }else if( cmd_[0] == 'e'){
        device_to_change_ = 'e';
        engine_value_ = atoi(cmd_ + 2);
    }else if( cmd_[0] == 'r'){
        engine_gear_ = 'r';
    }else if( cmd_[0] == 'f'){
        engine_gear_ = 'f';
    }
    else{
        device_to_change_ = 'n';
    }

}

char BluetoothModule::getDeviceToChange() const {
    return device_to_change_;
}

char BluetoothModule::getEngineGear() const {
    return engine_gear_;
}

int BluetoothModule::getEngineValue() const {
    return engine_value_;
}

int BluetoothModule::getServoValue() const {
    return servo_value_;
}


void Engine::setSpeed() {

    if(bt_.getDeviceToChange() == 'e') {
        int speed = bt_.getEngineValue();
        speed_ = speed;

        if(bt_.getEngineGear() == 'f'){

            turn( speed, 1, 0);
            delay(10);
        }else if(bt_.getEngineGear() == 'r' ){
            turn( speed, 0, 1); //tutaj ciekawe dlaczego nie podświetla speed_ ale ustawiam piny tak żeby działały
            delay(10);
        }
    }
}

void Engine::engine_setup() {

    pinMode(control_pin_, OUTPUT);
    pinMode(power_pin_, OUTPUT);
    digitalWrite(power_pin_, HIGH);
    pinMode(GND_pin_, OUTPUT);
    digitalWrite(GND_pin_, LOW);

}

void Engine::turn(int control_pin_value, int power_pin_lvl, int gnd_pin_lvl) {

    if (power_pin_lvl == 1){
        analogWrite(control_pin_, control_pin_value);
        digitalWrite(power_pin_, HIGH);
        digitalWrite(GND_pin_, LOW);
    }else if(power_pin_lvl == 0){

        analogWrite(control_pin_, control_pin_value);
        digitalWrite(power_pin_, LOW);
        digitalWrite(GND_pin_, HIGH);
    }

}

void ControlEngine::setSpeed() {

    if(bt_.getDeviceToChange() == 's') {
        int speed = bt_.getServoValue(); //drugi slider jest jako "server" ale w naszym przypadku to control engine - silnik odpowiedzialny za prawo lewo
        speed_ = abs(speed); //bo speed może być ujemny w tym przypadku!

        if(speed < -10){

            turn( speed_, 1, 0);
            delay(10);
        }else if(speed > 10){
            turn( speed_, 0, 1); //tutaj ciekawe dlaczego nie podświetla speed_ ale ustawiam piny tak żeby działały
            delay(10);
        }
    }
}

void DistanceSensor::change_distance() {

    int czas;

    digitalWrite(trig_pin_, LOW);
    delayMicroseconds(2);
    digitalWrite(trig_pin_, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig_pin_, LOW);

    czas = pulseIn(echo_pin_, HIGH);
    distance_ = czas / 58;

}

void DistanceSensor::sensor_setup() {

    Serial.begin (9600);
    pinMode(trig_pin_, OUTPUT); //włączam pina
    pinMode(echo_pin_, INPUT);
}
