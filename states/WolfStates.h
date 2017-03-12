#ifndef WOLFSTATES_H
#define WOLFSTATES_H

#include <iostream>
#include "States.h"

template <class Type>
class WolfStates : public States<Type> {
    public:
        WolfStates(LimitedField<Type>* health=new LimitedField<Type>( (Type)Hp::WEREWOLF*2, FieldType::HEALTH ),
                   Damage<Type>* damage=new Damage<Type>((Type)Dmg::WEREWOLF*2),
                   Defence* defence=new Defence((double)TakeDamageCoef::WOLF,
                                                (double)TakeMagicDamageCoef::WOLF),
                   const std::string& title="Wolf",
                   UnitEnum uEnum=UnitEnum::WOLF,
                   UnitEnum uType=UnitEnum::ALIVE);
        virtual ~WolfStates();
};

template <class Type>
std::ostream& operator<<(std::ostream& out, const WolfStates<Type>& wolfStates);

#endif // WOLFSTATES_H
