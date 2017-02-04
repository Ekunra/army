#include "RogueAttack.h"

template <class Type>
RogueAttack<Type>::RogueAttack() {
    if ( DEBUG ) {
        std::cout << FO_B_GREEN << "       + " << FO_RESET;
        std::cout << FO_B << "RogueAttack" << FO_RESET << " created." << std::endl;
    }
}
template <class Type>
RogueAttack<Type>::~RogueAttack() {
    if ( DEBUG ) {
        std::cout << FO_B_RED << "      - - " << FO_RESET << "RogueAttack destructed." << std::endl;
    }
}

template <class Type>
void RogueAttack<Type>::attack(Unit<Type>* attacker, Unit<Type>* enemy) {
    std::cout << "      --- " << attacker->getName() 
    << " attacking " << enemy->getName() << std::endl;

    enemy->takeDamage(attacker);
    std::cout << "      * RogueAttack finished." << std::endl;
}

template class RogueAttack<int>;
template class RogueAttack<double>;
template class RogueAttack<float>;
