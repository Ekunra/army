#include "LightningBolt.h"

template <class Type>
LightningBolt<Type>::LightningBolt( SpellEnum sEnum,
                                    Type power,
                                    Type manaCost,
                                    const std::string& spellName )
    : Spell<Type>(sEnum, power, manaCost, spellName) {
        std::cout << " * +++ " << spellName << " created."<< std::endl;
    }
template <class Type>
LightningBolt<Type>::~LightningBolt() {
    std::cout << "   * --- LightningBolt destructed" << std::endl;
}

template class LightningBolt<int>;
template class LightningBolt<double>;
template class LightningBolt<float>;
