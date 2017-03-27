#ifndef PRIEST_H
#define PRIEST_H

#include <iostream>
#include "../SpellCaster.h"
#include "../../states/PriestStates.h"
#include "../../attack/PriestAttack.h"
#include "../../attack/PriestCounterAttack.h"

template <class Type>
class Priest : public SpellCaster<Type> {
    protected:
    public:
        Priest(const std::string& name);
        virtual ~Priest();

        virtual void cast(SpellEnum sEnum, SpellCaster<Type>* targetCaster);
        virtual void cast(SpellEnum sEnum, Unit<Type>* targetUnit);
};

template <class Type>
std::ostream& operator<<(std::ostream& out, const Priest<Type>& priest);

#endif // PRIEST_H
