#include "SpellCasterStates.h"

template <class Type>
SpellCasterStates<Type>::SpellCasterStates(LimitedField<Type>* mana,
                                            double damageDTmagicCoef,
                                            double healingTmagicCoef,
                                            double damageMTmagicCoef,
                                            double manaTmagicCoef )
                      : mana(mana),
                        damageDTmagicCoef(new double(damageDTmagicCoef/100)),
                        healingTmagicCoef(new double(healingTmagicCoef/100)),
                        damageMTmagicCoef(new double(damageMTmagicCoef/100)),
                        manaTmagicCoef(new double(manaTmagicCoef/100)) {
    if ( DEBUG ) {
        std::cout << FO_B_GREEN << "|          + " << FO_RESET;
        std::cout << FO_B << "SpellCasterStates" << FO_RESET <<" created" << std::endl;
    }
}
template <class Type>
SpellCasterStates<Type>::~SpellCasterStates() {
    delete mana;
    if ( DEBUG ) {
        std::cout << FO_B_RED << "      - " << FO_RESET;
        std::cout << "SpellCasterStates deleted." << std::endl;
    }
}


template <class Type>
const LimitedField<Type>& SpellCasterStates<Type>::getManaObj() const {
    return *this->mana;
}


template <class Type>
const Type& SpellCasterStates<Type>::getMana() const {
    return this->mana->getValue();
}
template <class Type>
const Type& SpellCasterStates<Type>::getManaLimit() const {
    return this->mana->getLimit();
}

template <class Type>
const double& SpellCasterStates<Type>::getDDTmCoef() const {
    return *this->damageDTmagicCoef;
}
template <class Type>
const double& SpellCasterStates<Type>::getHTmCoef() const {
    return *this->healingTmagicCoef;
}
template <class Type>
const double& SpellCasterStates<Type>::getDMTmCoef() const {
    return *this->damageMTmagicCoef;
}
template <class Type>
const double& SpellCasterStates<Type>::getMTmCoef() const {
    return *this->manaTmagicCoef;
}

template <class Type>
void SpellCasterStates<Type>::spendMana(SpellEnum sEnum, SpellCaster<Type>* caster) {
    std::cout << "   SpellCasterStates::spendMana : " << FO_B << "spell cost " << caster->getSpell(sEnum).getManaCost() << FO_RESET << std::endl;
    *this->mana -= caster->getSpell(sEnum).getManaCost();
}
template <class Type>
void SpellCasterStates<Type>::spendMana(Spell<Type> spell, SpellCaster<Type>* caster) {
    ;
}
template <class Type>
void SpellCasterStates<Type>::receiveMana(Spell<Type> spell, SpellCaster<Type>* caster) {
    ;
}

template class SpellCasterStates<int>;
template class SpellCasterStates<double>;
template class SpellCasterStates<float>;

template <class Type>
std::ostream& operator<<(std::ostream& out, const SpellCasterStates<Type>& spellCasterStates) {
    out << spellCasterStates.getManaObj();
    return out;
};

template std::ostream& operator<<(std::ostream& out, const SpellCasterStates<int>& scStates);
template std::ostream& operator<<(std::ostream& out, const SpellCasterStates<double>& scStates);
template std::ostream& operator<<(std::ostream& out, const SpellCasterStates<float>& scStates);
