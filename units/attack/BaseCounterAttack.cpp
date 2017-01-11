#include "BaseCounterAttack.h"

template <class Type>
BaseCounterAttack<Type>::BaseCounterAttack() {}

template <class Type>
BaseCounterAttack<Type>::~BaseCounterAttack() {
    std::cout << "    - - BaseCounterAttack destructed." << std::endl;
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
