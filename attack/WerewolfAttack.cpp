#include "WerewolfAttack.h"

template <class Type>
WerewolfAttack<Type>::WerewolfAttack() {
    if ( DEBUG ) {
        std::cout << FO_B_GREEN << "|       + " << FO_RESET;
        std::cout << FO_B << "WerewolfAttack" << FO_RESET << " created" << std::endl;
    }
}

template <class Type>
WerewolfAttack<Type>::~WerewolfAttack() {
    if ( DEBUG ) {
        std::cout << FO_B_RED << "         - " << FO_RESET;
        std::cout << "WerewolfAttack destructed." << std::endl;
    }
}

template <class Type>
void WerewolfAttack<Type>::attack(Unit<Type>* attacker, Unit<Type>* enemy) {
    BaseAttack<Type>::attack(attacker, enemy);
}

template class WerewolfAttack<int>;
template class WerewolfAttack<double>;
template class WerewolfAttack<float>;
