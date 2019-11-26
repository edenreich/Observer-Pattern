#ifndef OBSERVER_INTERFACE_H
#define OBSERVER_INTERFACE_H


class Observer
{

public:

    /**
     * Called when the observable state has changed.
     *
     * @return void
     */
    virtual void update() = 0;

};


#endif // OBSERVER_INTERFACE_H