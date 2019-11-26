#ifndef OBSERVABLE_INTERFACE_H
#define OBSERVABLE_INTERFACE_H

#include "observer.h"
#include <vector>


class Observable
{

public:

    /**
     * Add an observer to the list.
     * 
     * @param Observer * observer
     * @return void
     */
    virtual void add(Observer * observer) = 0;

    /**
     * Remove an observer from the list.
     * 
     * @param Observer * observer
     * @return void
     */
    virtual void remove(Observer * observer) = 0;

    /**
     * Notify all observers.
     * 
     * @param Observer * observer
     * @return void
     */
    virtual void notify() = 0;

private:

    /**
     * Store all observers.
     * 
     * @var std::vector<Observer *> observers
     */
    std::vector<Observer *> observers;

};


#endif // OBSERVABLE_INTERFACE_H