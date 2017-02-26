#include "Heal.h"

template <class Type>
Heal<Type>::Heal ( SpellEnum sEnum,
                   SpellEnum sType,
                   Type power,
                   Type manaCost,
                   const std::string& spellName )
    : Spell<Type> ( sEnum, sType, power, manaCost, spellName ) {

    if ( DEBUG ) {
        std::cout << FO_B_GREEN << "             * " << FO_RESET;
        std::cout << FO_B << spellName << FO_RESET << " created."<< std::endl;
    }
}
template <class Type>
Heal<Type>::~Heal() {
    if ( DEBUG ) {
        std::cout << FO_B_RED << "        * " << FO_RESET;
        std::cout << FO_B << this->getSpellName() << FO_RESET << " destructed" << std::endl;
    }
}

template class Heal<int>;
template class Heal<double>;
template class Heal<float>;
