#include "ManaPortion.h"

template <class Type>
ManaPortion<Type>::ManaPortion( SpellEnum sEnum,
                                Type power,
                                Type manaCost,
                                const std::string& spellName )
    : Spell<Type>(sEnum, power, manaCost, spellName) {

    if ( DEBUG ) {
        std::cout << FO_B_GREEN << "             * " << FO_RESET;
        std::cout << FO_B << spellName << FO_RESET << " created."<< std::endl;
    }
}
template <class Type>
ManaPortion<Type>::~ManaPortion() {
    if ( DEBUG ) {
        std::cout << FO_B_RED << "        * " << FO_RESET;
        std::cout << FO_B << this->getSpellName() << FO_RESET << " destructed" << std::endl;
    }
}

template class ManaPortion<int>;
template class ManaPortion<double>;
template class ManaPortion<float>;
