#ifndef VAMPIREINFECTABILITY_H
#define VAMPIREINFECTABILITY_H

#include <iostream>
#include "BaseAbility.h"
#include "../units/Unit.h"
#include "../states/VampireStates.h"
#include "../attack/VampireAttack.h"
#include "../attack/VampireCounterAttack.h"


template <class Type>
class Unit;

template <class Type>
class VampireInfectAbility : public BaseAbility<Type> {
    public:
        VampireInfectAbility(Unit<Type>* owner, const std::string& name="Vampire Infect Ability");
        virtual ~VampireInfectAbility();

        virtual void action(Unit<Type>* enemy);
};

#endif // VAMPIREINFECTABILITY_H
