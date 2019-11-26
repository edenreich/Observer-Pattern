
#include "observable.h"
#include "observer.h"

#include <iostream>
#include <algorithm>


class Car : public Observable
{

public:

    /**
     * Add an observer to the list.
     * 
     * @param Observer * observer
     * @return void
     */
    void add(Observer * observer) override
    {
        observers.push_back(observer);
    }

    /**
     * Remove an observer from the list.
     * 
     * @param Observer * observer
     * @return void
     */
    void remove(Observer * observer) override
    {
        auto iterator = std::find(observers.begin(), observers.end(), observer);

        if (iterator != observers.end()) {
            observers.erase(iterator);
        }
    }

    /**
     * Notify all observers.
     * 
     * @param Observer * observer
     * @return void
     */
    void notify() override
    {
        for (auto const & observer : observers) {
            observer->update();
        }
    }

    void start()
    {
        // notify all of the components.
        notify();
    }

private:

    /**
     * Store all observers.
     * 
     * @var std::vector<Observer *> observers
     */
    std::vector<Observer *> observers;
};

class LCD : public Observer
{

public:

    /**
     * Called when the observable state has changed.
     *
     * @return void
     */
    void update() override
    {
        turnOn();
    }

    /**
     * Turn on the display.
     * 
     * @return void
     */
    void turnOn()
    {
        std::cout << "LCD is now turned on.." << '\n';
        std::cout << "Welcome!" << '\n';
    }

};

class Airconditioner : public Observer
{

public:

    /**
     * Called when the observable state has changed.
     *
     * @return void
     */
    void update() override
    {
        turnOn();
    }

    /**
     * Turn on the airconditioner.
     * 
     * @return void
     */
    void turnOn()
    {
        std::cout << "Airconditioner is now turned on.." << '\n';
    }
};


int main(int argc, char const *argv[])
{
    Car car;

    // Register the car's components.
    LCD lcd;
    Airconditioner ac;

    car.add(&lcd);
    car.add(&ac);
    // and so on..

    car.start();

    return EXIT_SUCCESS;
}
