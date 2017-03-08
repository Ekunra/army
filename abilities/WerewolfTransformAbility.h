#ifndef WEREWOLFTRANSFORMABILITY_H
#define WEREWOLFTRANSFORMABILITY_H

#include <iostream>
#include "BaseAbility.h"
#include "../units/Unit.h"

template <class Type>
class Unit;

template <class Type>
class WerewolfTransformAbility : public BaseAbility<Type> {
    public:
        WerewolfTransformAbility(Unit<Type>* owner, const std::string& name="Werewolf Transform Ability");
        virtual ~WerewolfTransformAbility();

        virtual void action();
};

#endif // WEREWOLFTRANSFORMABILITY_H
