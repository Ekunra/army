#include "RogueAttack.h"

template <class Type>
RogueAttack<Type>::RogueAttack() {}
template <class Type>
RogueAttack<Type>::~RogueAttack() {
    std::cout << "  * RogueAttack destructed." << std::endl;
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
