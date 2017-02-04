#include "Heal.h"

template <class Type>
Heal<Type>::Heal ( SpellEnum sEnum,
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
Heal<Type>::~Heal() {
    std::cout << "   * --- Heal destructed" << std::endl;
}

template class Heal<int>;
template class Heal<double>;
template class Heal<float>;
