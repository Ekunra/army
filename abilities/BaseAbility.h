#ifndef BASEABILITY_H
#define BASEABILITY_H

#include <iostream>
#include "../units/Unit.h"

template <class Type>
class Unit;

template <class Type>
class BaseAbility {
    protected:
        Unit<Type>* owner;
        std::string* abilityName;
    public:
        BaseAbility(Unit<Type>* owner, const std::string& name="No Ablility");
        virtual ~BaseAbility();

        virtual void action(Unit<Type>* enemy);
        virtual void action();
};

#endif // BASEABILITY_H
