#include "VampireAttack.h"

template <class Type>
VampireAttack<Type>::VampireAttack() {
    if ( DEBUG ) {
        std::cout << FO_B_GREEN << "|    + " << FO_RESET;
        std::cout << FO_B << "VampireAttack" << FO_RESET << " created" << std::endl;
    }
}

template <class Type>
VampireAttack<Type>::~VampireAttack() {
    if ( DEBUG ) {
        std::cout << FO_B_RED << "      - " << FO_RESET;
        std::cout << "VampireAttack destructed." << std::endl;
    }
}


template <class Type>
void VampireAttack<Type>::attack(Unit<Type>* attacker, Unit<Type>* enemy) {
    std::cout << "      --- " << attacker->getName() << " attacking " << enemy->getName() << std::endl;
    bool alive = enemy->isAlive();
    Type enemyHealth;

        if ( alive ) {
            enemyHealth = enemy->getHitPoints();
            std::cout << "   While VampireAttack enemy is Alive and enemyHealth LEFT is = " << enemyHealth << std::endl;
        }
    
    enemy->takeDamage(attacker);

        if ( alive ) {
            if ( enemyHealth >= attacker->getLastDmg()) {
                attacker->getHealthField() += attacker->getLastDmg() / ((double)VampireDrinkBlood::COEF / 100);
                std::cout << "   Vampire get << " << attacker->getLastDmg() / ((double)VampireDrinkBlood::COEF / 100) << "points of health." << std::endl;
            } else {
                attacker->getHealthField() += enemyHealth / ((double)VampireDrinkBlood::COEF / 100);
                std::cout << "   Vampire get << " << enemyHealth / ((double)VampireDrinkBlood::COEF / 100) << "points of health." << std::endl;
            }
        }
    std::cout << "      --- " << attacker->getName() << " calling " << enemy->getName()  << "\'s counterAttack!" << std::endl;
    enemy->counterAttack(attacker);
    std::cout << "      --- " << attacker->getName() << "\'s attack finished" << std::endl;
}

template class VampireAttack<int>;
template class VampireAttack<double>;
template class VampireAttack<float>;
