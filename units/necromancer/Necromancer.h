#ifndef NECROMANCER_H
#define NECROMANCER_H

#include <iostream>
#include "../SpellCaster.h"
#include "../../states/NecromancerStates.h"
#include "../../observe/Observer.h"

template <class Type> class Observer;

template <class Type>
class Necromancer : public SpellCaster<Type>, public Observer<Type> {
    protected:
    public:
        Necromancer(const std::string& name);
        virtual ~Necromancer();

        virtual void cast(SpellEnum sEnum, SpellCaster<Type>* targetCaster);
        virtual void cast(SpellEnum sEnum, Unit<Type>* targetUnit);
};

template <class Type>
std::ostream& operator<<(std::ostream& out, const Necromancer<Type>& necromancer);

#endif // NECROMANCER_H
