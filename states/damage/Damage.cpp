#include "Damage.h"

template <class Type>
Damage<Type>::Damage(Type dmg)
    : maxDmg(new Type(dmg)), minDmg(new Type(round((dmg/10)*8))) {
        srand(time(NULL));
        std::cout << "   Damage Instance created." << std::endl;
    }

template <class Type>
Damage<Type>::~Damage() {
    delete maxDmg;
    delete minDmg;
    std::cout << "      - Damage Instance deleted." << std::endl;
}


template <class Type>
int Damage<Type>::randomize(int min, int range) {
    // std::cout << " - int randomize() works" << std::endl;
    return rand() % (range+1) + min;
}

template <class Type>
double Damage<Type>::randomize(double min, double range) {
    // std::cout << " - double randomize() works" << std::endl;
    return ( (double)(rand() % ((int)range*10+1) + ((int)min*10) ) / 10 );
}

template <class Type>
float Damage<Type>::randomize(float min, float range) {
    // std::cout << " - float randomize() works" << std::endl;
    return randomize((double)min, (double)range);
}

template <class Type>
const Type& Damage<Type>::getMaxDmg() const {
    return *this->maxDmg;
}
template <class Type>
const Type& Damage<Type>::getMinDmg() const {
    return *this->minDmg;
}
template <class Type>
Type Damage<Type>::getDamage() {
    return this->randomize(*this->minDmg, (*this->maxDmg-*this->minDmg));
}


template <class Type>
std::ostream& operator<<(std::ostream& out, const Damage<Type>& dmg) {
    out << dmg.getMinDmg() << '-' << dmg.getMaxDmg();
    return out;
}

template class Damage<int>;
template class Damage<double>;
template class Damage<float>;

template std::ostream& operator<<(std::ostream& out, const Damage<int>& dmg);
template std::ostream& operator<<(std::ostream& out, const Damage<double>& dmg);
template std::ostream& operator<<(std::ostream& out, const Damage<float>& dmg);
