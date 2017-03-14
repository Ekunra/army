#ifndef VAMPIRESTATES_H
#define VAMPIRESTATES_H

#include <iostream>
#include "States.h"

template <class Type>
class VampireStates : public States<Type> {
    public:
        VampireStates( LimitedField<Type>* health=new LimitedField<Type>( (Type)Hp::VAMPIRE, FieldType::HEALTH ),
                       Damage<Type>* damage=new Damage<Type>((Type)Dmg::VAMPIRE),
                       Defence* defence=new Defence((double)TakeDamageCoef::VAMPIRE,
                                                    (double)TakeMagicDamageCoef::VAMPIRE),
                       const std::string& title="Vampire",
                       UnitEnum uEnum=UnitEnum::VAMPIRE,
                       UnitEnum uType=UnitEnum::EVILSPIRIT );
        virtual ~VampireStates ();
};

template <class Type>
std::ostream& operator<<(std::ostream& out, const VampireStates<Type>& vampireStates);

#endif // VAMPIRESTATES_H
