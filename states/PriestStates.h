#ifndef PRIESTSTATES_H
#define PRIESTSTATES_H

#include <iostream>
#include "States.h"

template <class Type>
class PriestStates : public States<Type> {
    public:
        PriestStates(LimitedField<Type>* health=new LimitedField<Type>( (Type)Hp::PRIEST, FieldType::HEALTH ),
                   Damage<Type>* damage=new Damage<Type>((Type)Dmg::PRIEST),
                   Defence* defence=new Defence((double)TakeDamageCoef::PRIEST,
                                                (double)TakeMagicDamageCoef::PRIEST),
                   const std::string& title="Priest",
                   UnitEnum uEnum=UnitEnum::PRIEST,
                   UnitEnum uType=UnitEnum::ALIVE);
        virtual ~PriestStates();
};

template <class Type>
std::ostream& operator<<(std::ostream& out, const PriestStates<Type>& priestStates);

#endif // PRIESTSTATES_H
