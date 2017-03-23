#ifndef BERSERKERSTATES_H
#define BERSERKERSTATES_H

#include <iostream>
#include "States.h"

template <class Type>
class BerserkerStates : public States<Type> {
    public:
        BerserkerStates(LimitedField<Type>* health=new LimitedField<Type>( (Type)Hp::BERSERKER, FieldType::HEALTH ),
                   Damage<Type>* damage=new Damage<Type>((Type)Dmg::BERSERKER),
                   Defence* defence=new Defence((double)TakeDamageCoef::BERSERKER,
                                                (double)TakeMagicDamageCoef::BERSERKER),
                   const std::string& title="Berserker",
                   UnitEnum uEnum=UnitEnum::BERSERKER,
                   UnitEnum uType=UnitEnum::ALIVE);
        virtual ~BerserkerStates();
};

template <class Type>
std::ostream& operator<<(std::ostream& out, const BerserkerStates<Type>& berserkerStates);

#endif // BERSERKERSTATES_H