#ifndef NECROMANCERSTATES_H
#define NECROMANCERSTATES_H

#include <iostream>
#include "States.h"

template <class Type>
class NecromancerStates : public States<Type> {
    public:
        NecromancerStates(LimitedField<Type>* health=new LimitedField<Type>( (Type)Hp::NECROMANCER, FieldType::HEALTH ),
                   Damage<Type>* damage=new Damage<Type>((Type)Dmg::NECROMANCER),
                   Defence* defence=new Defence((double)TakeDamageCoef::NECROMANCER,
                                                (double)TakeMagicDamageCoef::NECROMANCER),
                   const std::string& title="Necromancer",
                   UnitEnum uEnum=UnitEnum::NECROMANCER,
                   UnitEnum uType=UnitEnum::ALIVE);
        virtual ~NecromancerStates();
};

template <class Type>
std::ostream& operator<<(std::ostream& out, const NecromancerStates<Type>& necromancerStates);

#endif // NECROMANCERSTATES_H
