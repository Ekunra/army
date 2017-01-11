#include "Damage.h"

template <class Type>
Damage<Type>::Damage(Type dmg)
    : maxDmg(new Type(dmg)), minDmg(new Type(round((dmg/10)*8))), lastDmg(new Type(0)) {
        Randomizer::launch();
        std::cout << "   Damage Instance created." << std::endl;
    }

template <class Type>
Damage<Type>::~Damage() {
    delete maxDmg;
    delete minDmg;
    delete lastDmg;
    std::cout << "        - Damage Instance deleted." << std::endl;
}


template <>
void Damage<int>::randomize() {
    std::cout << " - int randomize() works" << std::endl;
    *this->lastDmg = rand() % ((*this->maxDmg-*this->minDmg)+1) + *this->minDmg;
}

template <>
void Damage<double>::randomize() {
    std::cout << " - double randomize() works" << std::endl;
    *this->lastDmg = ( (double)(rand() % ((int)((*this->maxDmg-*this->minDmg)*10+1)) + ((int)(*this->minDmg * 10)) ) / 10 );
}

template <>
void Damage<float>::randomize() {
    std::cout << " - float randomize() works" << std::endl;
    *this->lastDmg = ( (float)(rand() % ((int)((*this->maxDmg-*this->minDmg)*10+1)) + ((int)(*this->minDmg * 10)) ) / 10 );
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
Type& Damage<Type>::getDamage() {
    /*this->*/randomize();
    return *this->lastDmg;
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
