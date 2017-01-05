#include "BaseAttack.h"

template <class Type>
BaseAttack<Type>::BaseAttack() {}

template <class Type>
BaseAttack<Type>::~BaseAttack() {
    std::cout << "    - - BaseAttack destructed." << std::endl;
}


template <class Type>
void BaseAttack<Type>::attack(Unit<Type>* attacker, Unit<Type>* enemy) {
    // std::cout << "      --- " << attacker->getName() 
    // << " attacking " << enemy->getName() 
    // << ", causing " << attacker->getDamage() 
    // << " dmg." <<std::endl;

    enemy->takeDamage(attacker);
    enemy->counterAttack(attacker);
}

template class BaseAttack<int>;
template class BaseAttack<double>;
template class BaseAttack<float>;
