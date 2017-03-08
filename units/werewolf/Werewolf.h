#ifndef WEREWOLF_H
#define WEREWOLF_H

#include <iostream>
#include "../Unit.h"
#include "../../Properties.h"
#include "../../abilities/BaseAbility.h"
#include "../../abilities/WerewolfTransformAbility.h"
#include "../../states/WerewolfStates.h"
#include "../../states/WolfStates.h"

template <class Type>
class Werewolf : public Unit<Type> {
    public:
        Werewolf(const std::string& name);
        virtual ~Werewolf();

        virtual void attack(Unit<Type>* enemy);
};

template <class Type>
std::ostream& operator<<(std::ostream& out, const Werewolf<Type>& werewolf);

#endif // WEREWOLF_H
