#include "Damage.h"

template <class Type>
Damage<Type>::Damage(Type dmg)
    : maxDmg(new Type(dmg)), minDmg(new Type(round(((float)dmg/10)*8))), lastDmg(new Type(0)), initialDmg(new Type(dmg)) {
        Randomizer::launch();
        if ( DEBUG ) {
            std::cout << FO_B_GREEN << "|  + " << FO_RESET;
            std::cout << FO_D_GREY << "Damage Instance created." << FO_RESET << std::endl;
        }
    }

template <class Type>
Damage<Type>::~Damage() {
    delete maxDmg;
    delete minDmg;
    delete lastDmg;
    delete initialDmg;
    if ( DEBUG ) {
        std::cout << FO_B_RED << "        - " << FO_RESET << "Damage Instance deleted." << std::endl;
    }
}


template <>
void Damage<int>::randomize() {
    if ( DEBUG ) {
        std::cout << " - int randomize() works" << std::endl;
    }
    *this->lastDmg = rand() % ((*this->maxDmg-*this->minDmg)+1) + *this->minDmg;
}

template <>
void Damage<double>::randomize() {
    if ( DEBUG ) {
        std::cout << " - double randomize() works" << std::endl;
    }
    *this->lastDmg = ( (double)(rand() % ((int)((*this->maxDmg-*this->minDmg)*10+1)) + ((int)(*this->minDmg * 10)) ) / 10 );
}

template <>
void Damage<float>::randomize() {
    if ( DEBUG ) {
        std::cout << " - float randomize() works" << std::endl;
    }
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
const Type& Damage<Type>::getLastDmg() const {
    return *this->lastDmg;
}

template <class Type>
Type& Damage<Type>::getDamage() {
    this->randomize();
    return *this->lastDmg;
}

template <class Type>
void Damage<Type>::modifyDmg(DamageModifyCoef coef) {
    double modCoef = (double)coef / 100;
    std::cout << "   Damage::modifyDmg() works. modCoef = " << modCoef << std::endl;
    *this->maxDmg *= modCoef;
    *this->minDmg = (Type)(round(((float)(*this->maxDmg)/10)*8));
}

template <class Type>
void Damage<Type>::resetToInitialDmg() {
    *this->maxDmg = *this->initialDmg;
    *this->minDmg = (Type)(round(((float)(*this->initialDmg)/10)*8));
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
