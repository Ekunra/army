#ifndef HEALERSTATES_H
#define HEALERSTATES_H

#include <iostream>
#include "States.h"

template <class Type>
class HealerStates : public States<Type> {
    public:
        HealerStates(LimitedField<Type>* health=new LimitedField<Type>( (Type)Hp::HEALER, FieldType::HEALTH ),
                   Damage<Type>* damage=new Damage<Type>((Type)Dmg::HEALER),
                   Defence* defence=new Defence((double)TakeDamageCoef::HEALER,
                                                (double)TakeMagicDamageCoef::HEALER),
                   const std::string& title="Healer",
                   UnitEnum uEnum=UnitEnum::HEALER,
                   UnitEnum uType=UnitEnum::ALIVE);
        virtual ~HealerStates();
};

template <class Type>
std::ostream& operator<<(std::ostream& out, const HealerStates<Type>& healerStates);

#endif // HEALERSTATES_H
