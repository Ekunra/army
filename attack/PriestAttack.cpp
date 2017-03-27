#include "PriestAttack.h"

template <class Type>
PriestAttack<Type>::PriestAttack() {
    if ( DEBUG ) {
        std::cout << FO_B_GREEN << "|      + " << FO_RESET;
        std::cout << FO_B << "PriestAttack" << FO_RESET << " created" << std::endl;
    }
}

template <class Type>
PriestAttack<Type>::~PriestAttack() {
    if ( DEBUG ) {
        std::cout << FO_B_RED << "        - " << FO_RESET;
        std::cout << "PriestAttack destructed." << std::endl;
    }
}


template <class Type>
void PriestAttack<Type>::attack(Unit<Type>* attacker, Unit<Type>* enemy) {
    std::cout << "      --- " << attacker->getName() 
    << " attacking " << enemy->getName() << std::endl;
    // << ", causing " << attacker->getDamage() 
    // << " dmg." <<std::endl;

    if ( enemy->getUType() == UnitEnum::EVILSPIRIT ) {
        attacker->getStatesAddress()->getDamageAddress()->modifyDmg(DamageModifyCoef::EVILSPIRIT_PRIEST_ATTACK);
    }

    enemy->takeDamage(attacker);

    if ( enemy->getUType() == UnitEnum::EVILSPIRIT ) {
        attacker->getStatesAddress()->getDamageAddress()->resetToInitialDmg();
    }

    std::cout << "      --- " << attacker->getName() << " calling " << enemy->getName()  << "\'s counterAttack!" << std::endl;
    enemy->counterAttack(attacker);
    std::cout << "      --- " << attacker->getName() << "\'s attack finished" << std::endl;
}

template class PriestAttack<int>;
template class PriestAttack<double>;
template class PriestAttack<float>;
