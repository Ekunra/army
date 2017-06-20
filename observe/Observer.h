#ifndef OBSERVER_H
#define OBSERVER_H

#include <iostream>
#include <set>
#include "../units/Unit.h"
#include "../units/necromancer/Necromancer.h"

template <class Type> class Necromancer;
template <class Type> class Unit;

template <class Type>
class Observer {
    protected:
        Necromancer<Type>* owner;
        std::set<Unit<Type>*>* observables;
        
    public:
        Observer(Necromancer<Type>* necr);
        virtual ~Observer();

        void attachObservable();
        void dettachObservable();
        void notifyObservable();
};

#endif // OBSERVER_H
