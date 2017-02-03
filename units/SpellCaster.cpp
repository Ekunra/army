#include "SpellCaster.h"

template <class Type>
SpellCaster<Type>::SpellCaster(const std::string& name,
            SpellCasterStates<Type>* spellCasterStates,
            BaseAbility<Type>* priAbility,
            BaseAbility<Type>* secAbility,
            BaseAttack<Type>* baseAttack,
            BaseCounterAttack<Type>* baseCounterAttack)
                : Unit<Type> (  name,
                                spellCasterStates,
                                priAbility,
                                secAbility,
                                baseAttack,
                                baseCounterAttack ),
                  spellCasterStates(spellCasterStates),
                  spellBook(new SpellBook<Type>() ) {}
template <class Type>
SpellCaster<Type>::~SpellCaster() {
    delete spellCasterStates;
    delete spellBook;
}

template <class Type>
const Type& SpellCaster<Type>::getMana() const {}
template <class Type>
const Type& SpellCaster<Type>::getManaLimit() const {}

template <class Type>
void SpellCaster<Type>::castDDTMagic(SpellEnum sEnum, Unit<Type>* enemy) {}
template <class Type>
void SpellCaster<Type>::castHTMagic(SpellEnum sEnum, Unit<Type>* enemy) {}
template <class Type>
void SpellCaster<Type>::castMTMagic(SpellEnum sEnum, SpellCaster* friendly) {}

template class SpellCaster<int>;
template class SpellCaster<double>;
template class SpellCaster<float>;

template <class Type>
std::ostream& operator<<(std::ostream& out, const SpellCaster<Type>& spellCaster) {};

template std::ostream& operator<<(std::ostream& out, const SpellCaster<int>& spellCaster);
template std::ostream& operator<<(std::ostream& out, const SpellCaster<double>& spellCaster);
template std::ostream& operator<<(std::ostream& out, const SpellCaster<float>& spellCaster);
