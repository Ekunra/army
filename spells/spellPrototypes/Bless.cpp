#include "Bless.h"

template <class Type>
Bless<Type>::Bless( SpellEnum sEnum,
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
Bless<Type>::~Bless() {
    std::cout << "   * --- Bless destructed" << std::endl;
}

template class Bless<int>;
template class Bless<double>;
template class Bless<float>;
