#ifndef WIZARD_H
#define WIZARD_H

#include <iostream>
#include "../SpellCaster.h"

template <class Type>
class Wizard : public SpellCaster<Type> {
    protected:
    public:
        Wizard(const std::string& name);
        virtual ~Wizard();

        virtual void cast(SpellEnum sEnum, SpellCaster<Type>* someCaster);
        virtual void cast(SpellEnum sEnum, Unit<Type>* enemy);
};

template <class Type>
std::ostream& operator<<(std::ostream& out, const Wizard<Type>& wizard);

#endif // WIZARD_H
