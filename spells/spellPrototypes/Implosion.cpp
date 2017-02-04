#include "Implosion.h"

template <class Type>
Implosion<Type>::Implosion ( SpellEnum sEnum,
                             Type power,
                             Type manaCost,
                             const std::string& spellName )
                             : Spell<Type> ( sEnum,
                                             power,
                                             manaCost,
                                             spellName ) {
    std::cout << " * +++ " << spellName << " created."<< std::endl;
}
template <class Type>
Implosion<Type>::~Implosion() {
    std::cout << "   * --- Implosion destructed" << std::endl;
}

template class Implosion<int>;
template class Implosion<double>;
template class Implosion<float>;
