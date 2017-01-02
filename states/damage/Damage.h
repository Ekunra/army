#ifndef DAMAGE_H
#define DAMAGE_H

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

template <class Type>
class Damage {
    protected:
        Type* maxDmg;
        Type* minDmg;

        int randomize(int min, int max);
        double randomize(double min, double max);
        float randomize(float min, float max);

    public:
        Damage(Type dmg);
        ~Damage();

        const Type getMaxDmg() const;
        const Type getMinDmg() const;
        Type getDamage();
};

template <class Type>
std::ostream& operator<<(std::ostream& out, const Damage<Type>& dmg);

#endif // DAMAGE_H
