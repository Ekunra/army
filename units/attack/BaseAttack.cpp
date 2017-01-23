#include "BaseAttack.h"

template <class Type>
BaseAttack<Type>::BaseAttack() {
    if ( DEBUG ) {
        std::cout << FO_B_GREEN << "     + " << FO_RESET;
        std::cout << FO_B << "BaseAttack" << FO_RESET << " created" << std::endl;
    }
}

template <class Type>
BaseAttack<Type>::~BaseAttack() {
    if ( DEBUG ) {
        std::cout << FO_B_RED << "      - " << FO_RESET;
        std::cout << "BaseAttack destructed." << std::endl;
    }
}


template <class Type>
void BaseAttack<Type>::attack(Unit<Type>* attacker, Unit<Type>* enemy) {
    std::cout << "      --- " << attacker->getName() 
    << " attacking " << enemy->getName() << std::endl;
    // << ", causing " << attacker->getDamage() 
    // << " dmg." <<std::endl;

    enemy->takeDamage(attacker);
    std::cout << "      --- " << attacker->getName() << " calling " << enemy->getName()  << "\'s counterAttack!" << std::endl;
    enemy->counterAttack(attacker);
    std::cout << "      --- " << attacker->getName() << "\'s attack finished" << std::endl;
}

template class BaseAttack<int>;
template class BaseAttack<double>;
template class BaseAttack<float>;
