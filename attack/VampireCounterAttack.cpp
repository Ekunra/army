#include "VampireCounterAttack.h"

template <class Type>
VampireCounterAttack<Type>::VampireCounterAttack() {
    if ( DEBUG ) {
        std::cout << FO_B_GREEN << "|       + " << FO_RESET;
        std::cout << FO_B << "VampireCounterAttack" << FO_RESET << " created." << std::endl;
    }
}

template <class Type>
VampireCounterAttack<Type>::~VampireCounterAttack() {
    if ( DEBUG ) {
        std::cout << FO_B_RED << "         - " << FO_RESET;
        std::cout << "VampireCounterAttack destructed." << std::endl;
    }
}


template <class Type>
void VampireCounterAttack<Type>::counterAttack(Unit<Type>* counterAttacker, Unit<Type>* enemy) {
    std::cout << "      --- " << counterAttacker->getName() 
    << " counter-attacking " << enemy->getName() << std::endl;
    // << ", causing " << counterAttacker->getDamage()/2 
    // << " dmg." <<std::endl;
    bool alive = enemy->isAlive();
    Type enemyHealth;

        if ( alive ) {
            enemyHealth = enemy->getHitPoints();
            std::cout << "   While VampireCounterAttack enemy is Alive and enemyHealth LEFT is = " << enemyHealth << std::endl;
        }

    enemy->takeCADamage(counterAttacker);

        if ( alive ) {
            if ( enemyHealth >= counterAttacker->getLastDmg()) {
                counterAttacker->getHealthField() += (counterAttacker->getLastDmg() * ((double)VampireDrinkBlood::COEF / 100)) / 2;
                std::cout << "   Vampire get << " << (counterAttacker->getLastDmg() * ((double)VampireDrinkBlood::COEF / 100)) / 2 << "points of health. Vampire health is " << counterAttacker->getHealthField() << std::endl;
            } else {
                counterAttacker->getHealthField() += (enemyHealth * ((double)VampireDrinkBlood::COEF / 100)) / 2;
                std::cout << "   Vampire get << " << (enemyHealth * ((double)VampireDrinkBlood::COEF / 100)) / 2 << "points of health. Vampire health is " << counterAttacker->getHealthField() << std::endl;
            }
        }
}

template class VampireCounterAttack<int>;
template class VampireCounterAttack<double>;
template class VampireCounterAttack<float>;
