#include "SpellCaster.h"

template <class Type>
void SpellCaster<Type>::prepareToCast(SpellEnum sEnum) {
    this->haveSpell(sEnum);
    this->haveEnoughMana(sEnum);
    this->spendMana(sEnum);
}

template <class Type>
void SpellCaster<Type>::haveEnoughMana(Type manaNeeded) {
        std::cout << FO_B << "   - Do we have enough Mana?" << FO_RESET << std::endl;
    if ( manaNeeded <= this->spellCasterStates->getMana() ) {
        std::cout << "   - Yes, you have enough mana for casting spell." << std::endl;
        return;
    }
    throw NotEnoughManaException("You haven't enough mana for Spell casting");
}
template <class Type>
void SpellCaster<Type>::haveSpell(SpellEnum sEnum) {
    std::cout << FO_B << "   - Do we have such a Spell?" << FO_RESET << std::endl;
    if ( this->spellBook->haveSpell(sEnum) ) {
        // throw NoSuchSpellException("You haven't such a Spell");
        std::cout << "   - Yes, you have such Spell." << std::endl;
        return;
    }
    throw NoSuchSpellException("You don't have such a Spell");
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
void SpellCaster<Type>::takeMagic(MTSpell<Type>* spell) {
    std::cout << "   " << FO_D_GREY << this->getName() << FO_RESET << " takeMagic(MTSpell<Type>* spell) works" << std::endl;
    if ( this->Unit<Type>::isAlive() ) {
        this->spellCasterStates->receiveMana(spell);
    } else {
        std::cout << "   " << this->getName() << "is not alive and can't receive MTSpell, deleting SPELL" << std::endl;
        delete spell;
    }
}
template <class Type>
void SpellCaster<Type>::takeMagic(DMTSpell<Type>* spell) {
    std::cout << "   " << FO_D_GREY << this->getName() << FO_RESET << " takeMagic(DMTSpell<Type>* spell) works" << std::endl;
    if ( this->Unit<Type>::isAlive() ) {
        this->spellCasterStates->spendMana(spell);
    } else {
        std::cout << "   " << this->getName() << "is not alive and can't receive DMTSpell, deleting SPELL" << std::endl;
        delete spell;
    }
}
template <class Type>
void SpellCaster<Type>::spendMana(SpellEnum sEnum) {
    std::cout << "   SpellCaster::spendMana(SpellEnum sEnum) works" << std::endl;
    this->spellCasterStates->spendMana(sEnum, this);
}

template <class Type>
void SpellCaster<Type>::cast(SpellEnum sEnum, SpellCaster<Type>* someCaster) {
    try {
        if ( this->Unit<Type>::isAlive() ) {
            this->prepareToCast(sEnum);
            std::cout << FO_B << this->getName() << FO_RESET;
            std::cout << "'s Spellcaster::cast(SpellEnum, SpellCaster*) received ";
            std::cout << someCaster->getName() << " for sending it to baseCast" << std::endl;
            this->baseCast->action(sEnum, this, someCaster);
        }
    } catch (ArmyException e) {
        e.show();
    }
}
template <class Type>
void SpellCaster<Type>::cast(SpellEnum sEnum, Unit<Type>* enemy) {
    try {
        if ( this->Unit<Type>::isAlive() ) {
            this->prepareToCast(sEnum);
            std::cout << FO_B << this->getName() << FO_RESET;
            std::cout << "'s Spellcaster::cast(SpellEnum, Unit*) received ";
            std::cout << enemy->getName() << " for sending it to baseCast" << std::endl;
            this->baseCast->action(sEnum, this, enemy);
        }
    } catch (ArmyException e) {
        e.show();
    }
}

template class SpellCaster<int>;
template class SpellCaster<double>;
template class SpellCaster<float>;

template <class Type>
std::ostream& operator<<(std::ostream& out, const SpellCaster<Type>& spellCaster) {
    out << *((Unit<Type>*)(&spellCaster));
    if ( spellCaster.getUEnum() != UnitEnum::WEREWOLF &&
         spellCaster.getUEnum() != UnitEnum::WOLF &&
         spellCaster.getUEnum() != UnitEnum::VAMPIRE ) {
        out << FO_D_GREY << " | " << FO_RESET;
        out << spellCaster.getSpellCasterStates();
    }
    return out;
};

template std::ostream& operator<<(std::ostream& out, const SpellCaster<int>& spellCaster);
template std::ostream& operator<<(std::ostream& out, const SpellCaster<double>& spellCaster);
template std::ostream& operator<<(std::ostream& out, const SpellCaster<float>& spellCaster);
