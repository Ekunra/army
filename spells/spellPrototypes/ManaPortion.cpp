#include "ManaPortion.h"

template <class Type>
ManaPortion<Type>::ManaPortion(SpellEnum sEnum, Type power, Type manaCost, const std::string& spellName)
    : Spell<Type>(sEnum, power, manaCost, spellName) {
        std::cout << " * +++ " << spellName << " created."<< std::endl;
    }
template <class Type>
ManaPortion<Type>::~ManaPortion() {
    std::cout << "   * --- ManaPortion destructed" << std::endl;
}

template class ManaPortion<int>;
template class ManaPortion<double>;
template class ManaPortion<float>;
