#include "WerewolfInfectAbility.h"

template <class Type>
WerewolfInfectAbility<Type>::WerewolfInfectAbility(Unit<Type>* owner, const std::string& name)
    : BaseAbility<Type>(owner, name) {

    if ( DEBUG ) {
        std::cout << FO_B_GREEN << "|      + " << FO_RESET;
        std::cout << FO_B << "WerewolfInfectAbility" << FO_RESET << " created." << std::endl;
    }
}
template <class Type>
WerewolfInfectAbility<Type>::~WerewolfInfectAbility() {
    if ( DEBUG ){
        std::cout << FO_B_RED << "        - " << FO_RESET;
        std::cout << "WerewolfInfectAbility destructed." << std::endl;
    }
}

template <class Type>
void WerewolfInfectAbility<Type>::action(Unit<Type>* enemy) {
    enemy->setName(...);
    enemy->setStates(...);
    enemy->setAltStates(...);
    enemy->setAttack(...);
    enemy->setCounterAttack(...);
    enemy->setPrimaryAbility(...);
    enemy->setSecondaryAbility(...);
}


template class WerewolfInfectAbility<int>;
template class WerewolfInfectAbility<double>;
template class WerewolfInfectAbility<float>;
