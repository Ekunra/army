#include "WerewolfTransformAbility.h"

template <class Type>
WerewolfTransformAbility<Type>::WerewolfTransformAbility(Unit<Type>* owner, const std::string& name)
    : BaseAbility<Type>(owner, name) {

    if ( DEBUG ) {
        std::cout << FO_B_GREEN << "|      + " << FO_RESET;
        std::cout << FO_B << "WerewolfTransformAbility" << FO_RESET << " created." << std::endl;
    }
}
template <class Type>
WerewolfTransformAbility<Type>::~WerewolfTransformAbility() {
    if ( DEBUG ){
        std::cout << FO_B_RED << "        - " << FO_RESET;
        std::cout << "WerewolfTransformAbility destructed." << std::endl;
    }
}

template <class Type>
void WerewolfTransformAbility<Type>::action() {
    // std::cout << FO_B_RED << this->owner->getTitle() << " " << FO_RESET << FO_B << this->owner->getName() << FO_RESET << " have WerewolfTransformAbility." << std::endl;
    States<Type>* temp = this->owner->getStatesAddress();
    this->owner->setStates(this->owner->getAltStatesAddress());
    this->owner->setAltStates(temp);
    temp = NULL;
    delete temp;
}


template class WerewolfTransformAbility<int>;
template class WerewolfTransformAbility<double>;
template class WerewolfTransformAbility<float>;
