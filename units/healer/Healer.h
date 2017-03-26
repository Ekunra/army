#ifndef HEALER_H
#define HEALER_H

#include <iostream>
#include "../SpellCaster.h"
#include "../../states/HealerStates.h"

template <class Type>
class Healer : public SpellCaster<Type> {
    protected:
    public:
        Healer(const std::string& name);
        virtual ~Healer();

        virtual void cast(SpellEnum sEnum, SpellCaster<Type>* targetCaster);
        virtual void cast(SpellEnum sEnum, Unit<Type>* targetUnit);
};

template <class Type>
std::ostream& operator<<(std::ostream& out, const Healer<Type>& healer);

#endif // HEALER_H
