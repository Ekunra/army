#include "FireBall.h"

template <class Type>
FireBall<Type>::FireBall ( SpellEnum sEnum,
                           Type power,
                           Type manaCost,
                           const std::string& spellName )
                           : Spell<Type>( sEnum,
                                          power,
                                          manaCost,
                                          spellName ) {
    if ( DEBUG ) {
        std::cout << " * +++ " << spellName << " created."<< std::endl;
    }
}
template <class Type>
FireBall<Type>::~FireBall() {
    std::cout << "   * --- FireBall destructed" << std::endl;
}

template class FireBall<int>;
template class FireBall<double>;
template class FireBall<float>;
