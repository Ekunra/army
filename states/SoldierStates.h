#ifndef SOLDIERSTATES_H
#define SOLDIERSTATES_H

#include <iostream>
#include "States.h"

template <class Type>
class SoldierStates : public States<Type> {
    public:
        SoldierStates(LimitedField<Type>* health=new LimitedField<Type>( (Type)Hp::SOLDIER, FieldType::HEALTH ),
                   Damage<Type>* damage=new Damage<Type>((Type)Dmg::SOLDIER),
                   Defence* defence=new Defence((double)TakeDamageCoef::SOLDIER,
                                                (double)TakeMagicDamageCoef::SOLDIER),
                   const std::string& title="Soldier",
                   UnitEnum uEnum=UnitEnum::SOLDIER,
                   UnitEnum uType=UnitEnum::ALIVE);
        virtual ~SoldierStates();
};

template <class Type>
std::ostream& operator<<(std::ostream& out, const SoldierStates<Type>& soldierStates);

#endif // SOLDIERSTATES_H
