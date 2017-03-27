#include "PriestCounterAttack.h"

template <class Type>
PriestCounterAttack<Type>::PriestCounterAttack() {
    if ( DEBUG ) {
        std::cout << FO_B_GREEN << "|      + " << FO_RESET;
        std::cout << FO_B << "PriestCounterAttack" << FO_RESET << " created." << std::endl;
    }
}

template <class Type>
PriestCounterAttack<Type>::~PriestCounterAttack() {
    if ( DEBUG ) {
        std::cout << FO_B_RED << "        - " << FO_RESET;
        std::cout << "PriestCounterAttack destructed." << std::endl;
    }
}


template <class Type>
void PriestCounterAttack<Type>::counterAttack(Unit<Type>* counterAttacker, Unit<Type>* enemy) {
    std::cout << "      --- " << counterAttacker->getName() 
    << " counter-attacking " << enemy->getName() << std::endl;
    // << ", causing " << counterAttacker->getDamage()/2 
    // << " dmg." <<std::endl;

    if ( enemy->getUType() == UnitEnum::EVILSPIRIT ) {
        counterAttacker->getStatesAddress()->getDamageAddress()->modifyDmg(DamageModifyCoef::EVILSPIRIT_PRIEST_ATTACK);
    }

    enemy->takeCADamage(counterAttacker);

    if ( enemy->getUType() == UnitEnum::EVILSPIRIT ) {
        counterAttacker->getStatesAddress()->getDamageAddress()->resetToInitialDmg();
    }
}

template class PriestCounterAttack<int>;
template class PriestCounterAttack<double>;
template class PriestCounterAttack<float>;
