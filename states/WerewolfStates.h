#ifndef WEREWOLFSTATES_H
#define WEREWOLFSTATES_H

#include <iostream>
#include "States.h"

template <class Type>
class WerewolfStates : public States<Type> {
    public:
        WerewolfStates( LimitedField<Type>* health=new LimitedField<Type>( (Type)Hp::WEREWOLF, FieldType::HEALTH ),
                        Damage<Type>* damage=new Damage<Type>((Type)Dmg::WEREWOLF),
                        Defence* defence=new Defence((double)TakeDamageCoef::WEREWOLF,
                                                     (double)TakeMagicDamageCoef::WEREWOLF),
                        const std::string& title="Werewolf",
                        UnitEnum uEnum=UnitEnum::WEREWOLF,
                        UnitEnum uType=UnitEnum::ALIVE );
        virtual ~WerewolfStates();
};

template <class Type>
std::ostream& operator<<(std::ostream& out, const WerewolfStates<Type>& werewolfStates);

#endif // WEREWOLFSTATES_H
