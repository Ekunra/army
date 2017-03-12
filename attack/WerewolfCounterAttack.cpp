#include "WerewolfCounterAttack.h"

template <class Type>
WerewolfCounterAttack<Type>::WerewolfCounterAttack() {
    if ( DEBUG ) {
        std::cout << FO_B_GREEN << "|       + " << FO_RESET;
        std::cout << FO_B << "WerewolfCounterAttack" << FO_RESET << " created." << std::endl;
    }
}

template <class Type>
WerewolfCounterAttack<Type>::~WerewolfCounterAttack() {
    if ( DEBUG ) {
        std::cout << FO_B_RED << "         - " << FO_RESET;
        std::cout << "WerewolfCounterAttack destructed." << std::endl;
    }
}

template <class Type>
void WerewolfCounterAttack<Type>::counterAttack(Unit<Type>* counterAttacker, Unit<Type>* enemy) {
    BaseCounterAttack<Type>::counterAttack(counterAttacker, enemy);
}


template class WerewolfCounterAttack<int>;
template class WerewolfCounterAttack<double>;
template class WerewolfCounterAttack<float>;
