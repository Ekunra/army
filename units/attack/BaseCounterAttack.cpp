#include "BaseCounterAttack.h"

template <class Type>
BaseCounterAttack<Type>::BaseCounterAttack() {
    if ( DEBUG ) {
        std::cout << FO_B_GREEN << "     + " << FO_RESET;
        std::cout << FO_B << "BaseCounterAttack" << FO_RESET << " created." << std::endl;
    }
}

template <class Type>
BaseCounterAttack<Type>::~BaseCounterAttack() {
    if ( DEBUG ) {
        std::cout << FO_B_RED << "      - " << FO_RESET;
        std::cout << "BaseCounterAttack destructed." << std::endl;
    }
}


template <class Type>
void BaseCounterAttack<Type>::counterAttack(Unit<Type>* counterAttacker, Unit<Type>* enemy) {
    std::cout << "      --- " << counterAttacker->getName() 
    << " counter-attacking " << enemy->getName() << std::endl;
    // << ", causing " << counterAttacker->getDamage()/2 
    // << " dmg." <<std::endl;

    enemy->takeCADamage(counterAttacker);
}

template class BaseCounterAttack<int>;
template class BaseCounterAttack<double>;
template class BaseCounterAttack<float>;
