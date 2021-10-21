#include <Arduino.h>
#include <SoftwareSerial.h>
#include <string.h>
#ifndef TESTOWY_1_CAR_MODULES_HPP
#define TESTOWY_1_CAR_MODULES_HPP

//int convert_to_int(char cmd[100]){
//    return
//};
#define INF 20000;

/** BluetoothModule - stworzony do komunikacji z innym urządzenie np telefon i sterowaniem zdalnym
 *  Obsługiwany do aplikacji RoboRemo z dwoma sliderami - osbgługujący skręt samochodu i napięcie zasilania,
 *  dwoma przyciskami - które obsługują biegi samochodu
**/
class BluetoothModule{
public:
    /**
     * Konstruktor który tworzy pola klas i nadaję początkową wartość silników na 0,
     * @param rx_pin - pin reprezentujący rzeczywiste podłączenie w Arduino, rx jest pinem rx od arduino czyli na bluetooth module tx
     * @param tx_pin - pin reprezentujący rzeczywiste podłączenie w Arduino, tx jest pinem rx od arduino czyli na bluetooth module rx
     */
    BluetoothModule(const int& rx_pin, const int& tx_pin): rx_pin_(rx_pin), tx_pin_(tx_pin), serial_bt_(SoftwareSerial(rx_pin_, tx_pin_)), device_to_change_('n'), engine_gear_('f'), engine_value_(0), servo_value_(0) { }

    /**
     * metoda odpowiedzialna za ustawienie urządzenia z płytką arduino
     */
    void bluetooth_setup(){ serial_bt_.begin(9600); }

    /**
     * na początku funkcja wywołuje metodę prywatną read_cmd
     * Funkcja która zczytuje wartości wysyłane przez przyciski lub slidery
     * Wartości są przekazywane jako stringi: "l xxx" gdzie l - to litera opisująca urządzenie, do wyboru: 's', 'e', 'r', 'f', 'n'(opis przy opisie pól)
     * xxx - to wartość zadana
     */
    void read_device_value();


    int available(){
        return serial_bt_.available();
    }

    char getDeviceToChange() const;

    int getServoValue() const;

    int getEngineValue() const;

    char getEngineGear() const;


private:
    /**
     * metoda jest prywatną żebby zmniejszyć interfejs obiektu BluetoothModule, dodatkowo przy jej refaktoryzacji robię to tylko w obiekcie Bluetooth module
     * metoda ma za zadanie zczytywać znaki i zapisywać je w cmd_, jeżeli zostanie wysłany znak nowej lini
     */
    void read_cmd();
    const int& rx_pin_; //pin UART łączenia z arduino
    const int& tx_pin_; //pin UART łączenia z arduino rx jest podanawany przez pin 8 (zielony) dla arduino jest to tx
    SoftwareSerial serial_bt_; //serial bt jest to klasa stworzona aby piny inne niż 0/1 mogły się komunikować przez bluetooth, do stworzenia podaje się rx i tx
    char cmd_[100]; //polecenie zczytywane przez bluetooth w metodzie read_device_value
    int cmdIndex_ = 0;
    char device_to_change_; //przyjmuje 'n' jeżeli nic nie zmienia, 'e' jeżeli zmienia silnik, 's' jeżeli serwomechanizm
    char engine_gear_; // engine gear - są to biegi sa - domyślnie na przód 'f' lub 'r' do tyłu
    int engine_value_; //zapisywana wartość podawana na silnjik napędu
    int servo_value_; //wartość podawana na  silnik kierownica

};


/**
 * Klasa engine jest macierzystą klasą silnika po której dziedziczy controlEngine,
 * Posiada metody odpowiedzialne za ustawianie prędkości (napięcia na silniku) oraz jego włączenie.
 */
class Engine{
public:
    /**
     * Konstruktor inicjalizujący 4 pola klasy.
     * @param control_pin rzeczywisty pin kontroli na arduin
     * @param GND_pin  rzeczywisty pin jednej fazy
     * @param power_pin rzeczywisty pin drugiej fazy
     * @param bt moduł bluetooth podpięty do silnika
     */
    Engine(int control_pin, int GND_pin, int power_pin, BluetoothModule& bt): GND_pin_(GND_pin), power_pin_(power_pin), control_pin_(control_pin), bt_(bt), speed_(0){}


    /**
     * metoda odpowiedzialna za ustawienie pinów na OUTPUT i odpowiedni stan logiczny
     */
    void engine_setup();

    /**
     * Ustawienie działania samochodu
     * @param control_pin_value
     * @param power_pin_lvl
     * @param gnd_pin_lvl
     */
    void turn(int control_pin_value=0, int power_pin_lvl = 1, int gnd_pin_lvl=0);

    /**
     * Klasa która ustawia prędkość w zależności od informacji zwracanych przez moduł bluetooth
     */
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

/**
 * Klasa która dziedziczy po klasie Engine stworzona do obsługi silników kontroli pojazdu
 * klasa  korzysta z polimorfizmu i nadpisuje wirtualną klasę set speed
 */
class ControlEngine : public Engine{
public:
    /**
     * trzeba korzystać z dziedziczenia konstruktora przez klasy potomne w standardzie c++11
     */
    using Engine::Engine;
//    ControlEngine(int control_pin, int GND_pin, int power_pin, BluetoothModule& bt) : Engine( control_pin,  GND_pin,  power_pin, bt){}


    void setSpeed();


};

/**
 * Klasa obsługuję obiekt czujnika odległości, który znajduje się na początku
 */
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
    int distance_ = INF; // to może nie działać

};

#endif //TESTOWY_1_CAR_MODULES_HPP
