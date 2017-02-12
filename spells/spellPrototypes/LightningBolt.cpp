#include "LightningBolt.h"

template <class Type>
LightningBolt<Type>::LightningBolt( SpellEnum sEnum,
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
LightningBolt<Type>::~LightningBolt() {
    if ( DEBUG ) {
        std::cout << FO_B_RED << "        * " << FO_RESET;
        std::cout << FO_B << this->getSpellName() << FO_RESET << " destructed" << std::endl;
    }
}

template class LightningBolt<int>;
template class LightningBolt<double>;
template class LightningBolt<float>;
