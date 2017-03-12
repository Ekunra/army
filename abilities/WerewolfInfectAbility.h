#ifndef WEREWOLFINFECTABILITY_H
#define WEREWOLFINFECTABILITY_H

#include <iostream>
#include "BaseAbility.h"
#include "WerewolfTransformAbility.h"
#include "../units/Unit.h"
#include "../states/WerewolfStates.h"
#include "../states/WolfStates.h"


template <class Type>
class Unit;

template <class Type>
class WerewolfInfectAbility : public BaseAbility<Type> {
    public:
        WerewolfInfectAbility(Unit<Type>* owner, const std::string& name="Werewolf Infect Ability");
        virtual ~WerewolfInfectAbility();

        virtual void action(Unit<Type>* enemy);
};

#endif // WEREWOLFINFECTABILITY_H
