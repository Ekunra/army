#include "ManaDrain.h"

template <class Type>
ManaDrain<Type>::ManaDrain( SpellEnum sEnum,
                                SpellEnum sType,
                                Type power,
                                Type manaCost,
                                const std::string& spellName )
    : Spell<Type>(sEnum, sType, power, manaCost, spellName) {

    if ( DEBUG ) {
        std::cout << FO_B_GREEN << "             * " << FO_RESET;
        std::cout << FO_B << spellName << FO_RESET << " created."<< std::endl;
    }
}
template <class Type>
ManaDrain<Type>::~ManaDrain() {
    if ( DEBUG ) {
        std::cout << FO_B_RED << "        * " << FO_RESET;
        std::cout << FO_B << this->getSpellName() << FO_RESET << " destructed" << std::endl;
    }
}

template class ManaDrain<int>;
template class ManaDrain<double>;
template class ManaDrain<float>;
