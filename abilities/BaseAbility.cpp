#include "BaseAbility.h"

template <class Type>
BaseAbility<Type>::BaseAbility(Unit<Type>* owner, const std::string& name)
    : owner(owner), abilityName(new std::string(name)) {

    if ( DEBUG ) {
        std::cout << FO_B_GREEN << "|    + " << FO_RESET;
        std::cout << FO_B << "BaseAbility" << FO_RESET << " created." << std::endl;
    }
}
template <class Type>
BaseAbility<Type>::~BaseAbility() {
    if ( DEBUG ){
        std::cout << FO_B_RED << "      - " << FO_RESET;
        std::cout << "BaseAbility destructed." << std::endl;
    }
}

template <class Type>
void BaseAbility<Type>::action(Unit<Type>* enemy) {
    std::cout << "  !! It was a good try! But take care of your teeth! " << std::endl;
    enemy->counterAttack(owner);
}

template <class Type>
void BaseAbility<Type>::action() {
    std::cout << "  !! It was a good try! But take care of your teeth! " << std::endl;
}


template class BaseAbility<int>;
template class BaseAbility<double>;
template class BaseAbility<float>;
