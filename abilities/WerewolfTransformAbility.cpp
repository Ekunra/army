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
    States<Type>* temp;

    double coef = (double)this->owner->getAltStatesAddress()->getHitPointsLimit() / (double)this->owner->getStatesAddress()->getHitPointsLimit();
    this->owner->getAltStatesAddress()->getHealthField().mutate(this->owner->getStatesAddress()->getHealthField(), coef);

    temp = this->owner->getStatesAddress();

    this->owner->setStates(this->owner->getAltStatesAddress());
    this->owner->setAltStates(temp);

    temp = NULL;
    delete temp;
}


template class WerewolfTransformAbility<int>;
template class WerewolfTransformAbility<double>;
template class WerewolfTransformAbility<float>;
