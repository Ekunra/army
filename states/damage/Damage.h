#ifndef DAMAGE_H
#define DAMAGE_H

#include <iostream>
#include <cmath>
#include "Randomizer.h"
#include "../../macro_color.cpp"

template <class Type>
class Damage {
    protected:
        Type* maxDmg;
        Type* minDmg;
        Type* lastDmg;

        void randomize();

    public:
        Damage(Type dmg);
        virtual ~Damage();

        const Type& getMaxDmg() const;
        const Type& getMinDmg() const;
        const Type& getLastDmg() const;
        Type& getDamage();
};

template <class Type>
std::ostream& operator<<(std::ostream& out, const Damage<Type>& dmg);

#endif // DAMAGE_H
