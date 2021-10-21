
#ifndef TESTOWY_1_CAR_HPP
#define TESTOWY_1_CAR_HPP

#include "car_modules.hpp"

/**
 * Klasa car korzysta z wszystkich podzespołów samochodu: 2 silników, modułu bluetooth, czujnika odległości
 * na zasadzie agregacji. Do zespołu klasa odwołuję się poprzez referencję wcześniej stworzonych globalnych obiektów
 * są one globalne ze względu na działanie arduino.
 */
class Car{
public:
    /**
     * Za pomocą listy inicjalizacyjnej zostały zainicjalizowane pola klasy
     * @param bt
     * @param en
     * @param c_en
     * @param ds
     */
    Car(BluetoothModule& bt, Engine& en, ControlEngine& c_en, DistanceSensor& ds): bt_(bt), en_(en),c_en_(c_en), ds_(ds) {}
    /**
     * metoda setup korzysta z wszystkich dotychczasowych metód setup z każdego z podzespołów
     */
    void setup();


    bool is_connected(){
        return bt_.available() > 0;
    }
    /**
     * metoda drive jest odpowiedzialna za jazdę, użytkownik za pomocą infterfejsu operatorskiego z telefonu prowdzi
     */
    void drive();
private:
    BluetoothModule& bt_;
    Engine& en_;
    ControlEngine& c_en_;
    DistanceSensor& ds_;
};

#endif //TESTOWY_1_CAR_HPP
