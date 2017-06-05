#ifndef OBSERVER_H
#define OBSERVER_H

#include <iostream>

template <class Type>
class Observer {
    protected:
    public:
        Observer();
        virtual ~Observer();

        void attachObservable();
        void dettachObservable();
        void notifyObservable();
};

#endif // OBSERVER_H
