#include "SpellCaster.h"

template <class Type>
void SpellCaster<Type>::prepareToCast(SpellEnum sEnum) {
    if ( !this->haveSpell(sEnum) ) {
        return;
    }
    if ( !this->haveEnoughMana(sEnum) ) {
        return;
    }
    // this->haveEnoughMana(this->spellBook->getSpell(sEnum)->getManaCost());
    // this->spellCasterStates->spendMana(this->spellBook->getSpell(sEnum));
}

template <class Type>
SpellCaster<Type>::SpellCaster( SpellCasterStates<Type>* spellCasterStates,
                                BaseCast<Type>* baseCast,
                                const std::string& name,
                                States<Type>* states,
                                States<Type>* altStates,
                                BaseAbility<Type>* priAbility,
                                BaseAbility<Type>* secAbility,
                                BaseAttack<Type>* baseAttack,
                                BaseCounterAttack<Type>* baseCounterAttack )
                                    : baseCast(baseCast),
                                      spellBook(new SpellBook<Type>()),
                                      spellCasterStates(spellCasterStates),
                                      Unit<Type> (  name,
                                                    states,
                                                    altStates,
                                                    priAbility,
                                                    secAbility,
                                                    baseAttack,
                                                    baseCounterAttack ) {
    if ( DEBUG ) {
        std::cout << FO_B_GREEN << "|        + " << FO_RESET;
        std::cout << FO_B << "SpellCaster" << FO_RESET << " instance created." << std::endl;
    }
}
template <class Type>
SpellCaster<Type>::~SpellCaster() {
    delete spellBook;
    delete baseCast;
    delete spellCasterStates;
    if ( DEBUG ) {
        std::cout << FO_B_RED << "  - " << FO_RESET;
        std::cout << "SpellCaster (";
        std::cout << FO_B << Unit<Type>::getTitle() << FO_RESET;
        std::cout << ") instance destructed." << std::endl;
    }
}

template <class Type>
bool SpellCaster<Type>::haveEnoughMana(Type manaNeeded) {
        std::cout << "   - Do we have enough Mana?" << std::endl;
    if ( manaNeeded <= this->spellCasterStates->getMana() ) {
        std::cout << "   - Enough mana for casting spell." << std::endl;
        return true;
    } else {
        // throw NotEnoughManaException("Not ennough mana for spell casting.");
        std::cout << FO_B_L_RED << "   - You have not enough Mana!" << FO_RESET << std::endl;
    }
    return false;
}
template <class Type>
bool SpellCaster<Type>::haveSpell(SpellEnum sEnum) {
    std::cout << "   - Do we have such a Spell?" << std::endl;
    if ( this->spellBook->haveSpell(sEnum) ) {
        // throw NoSuchSpellException("You haven't such a Spell");
        std::cout << "   - Yes, you have such Spell." << std::endl;
        return true;
    }
    std::cout << FO_B_L_RED << "   - You have no such Spell!" << FO_RESET << std::endl;
    return false;
}

template <class Type>
const SpellCasterStates<Type>& SpellCaster<Type>::getSpellCasterStates() const {
    return *this->spellCasterStates;
}
template <class Type>
const SpellBook<Type>& SpellCaster<Type>::getSpellBook() const {
    return *this->spellBook;
}


template <class Type>
const Spell<Type>& SpellCaster<Type>::getSpell(SpellEnum& sEnum) const {
    return this->spellBook->getSpell(sEnum);
}
template <class Type>
const Type& SpellCaster<Type>::getMana() const {
    return this->spellCasterStates->getMana();
}
template <class Type>
const Type& SpellCaster<Type>::getManaLimit() const {
    return this->spellCasterStates->getManaLimit();
}

template <class Type>
void SpellCaster<Type>::cast(SpellEnum sEnum, SpellCaster<Type>* someCaster) {
    this->prepareToCast(sEnum);
    std::cout << FO_B << this->getName() << FO_RESET;
    std::cout << "'s Spellcaster::cast(SpellEnum, SpellCaster*) received ";
    std::cout << someCaster->getName() << " for sending it to baseCast" << std::endl;
    this->baseCast->action(sEnum, this, someCaster);
}
template <class Type>
void SpellCaster<Type>::cast(SpellEnum sEnum, Unit<Type>* enemy) {
    this->prepareToCast(sEnum);
    std::cout << FO_B << this->getName() << FO_RESET;
    std::cout << "'s Spellcaster::cast(SpellEnum, Unit*) received ";
    std::cout << enemy->getName() << " for sending it to baseCast" << std::endl;
    this->baseCast->action(sEnum, this, enemy);
}

template class SpellCaster<int>;
template class SpellCaster<double>;
template class SpellCaster<float>;

template <class Type>
std::ostream& operator<<(std::ostream& out, const SpellCaster<Type>& spellCaster) {
    out << *((Unit<Type>*)(&spellCaster));
    out << FO_D_GREY << " | " << FO_RESET;
    out << spellCaster.getSpellCasterStates();
    return out;
};

template std::ostream& operator<<(std::ostream& out, const SpellCaster<int>& spellCaster);
template std::ostream& operator<<(std::ostream& out, const SpellCaster<double>& spellCaster);
template std::ostream& operator<<(std::ostream& out, const SpellCaster<float>& spellCaster);
