#include "Damage.h"

template <class Type>
Damage<Type>::Damage(Type dmg)
    : maxDmg(new Type(dmg)), minDmg(new Type(round((dmg/10)*8))) {
        Randomizer::launch();
        std::cout << "   Damage Instance created." << std::endl;
    }

template <class Type>
Damage<Type>::~Damage() {
    delete maxDmg;
    delete minDmg;
    std::cout << "        - Damage Instance deleted." << std::endl;
}


template <>
int Damage<int>::randomize(int min, int range) {
    // std::cout << " - int randomize() works" << std::endl;
    return rand() % (range+1) + min;
}

template <>
double Damage<double>::randomize(double min, double range) {
    // std::cout << " - double randomize() works" << std::endl;
    return ( (double)(rand() % ((int)range*10+1) + ((int)min*10) ) / 10 );
}

template <>
float Damage<float>::randomize(float min, float range) {
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
    out << FO_D_GREY << "DMG:" << FO_RESET;
    out << FO_RED << dmg.getMinDmg() << FO_RESET;
    out << FO_D_GREY << '-' << FO_RESET;
    out << FO_RED << dmg.getMaxDmg() << FO_RESET;
    return out;
}

template class Damage<int>;
template class Damage<double>;
template class Damage<float>;

template std::ostream& operator<<(std::ostream& out, const Damage<int>& dmg);
template std::ostream& operator<<(std::ostream& out, const Damage<double>& dmg);
template std::ostream& operator<<(std::ostream& out, const Damage<float>& dmg);
