#include "SpellBook.h"

template <class Type>
SpellBook<Type>::SpellBook() : spellBook(new std::map<SpellEnum, Spell<Type>*>) {}

template <class Type>
SpellBook<Type>::~SpellBook() {
    std::cout << "   --- Start deleting spells from SpellBook. --- " << std::endl;
    typename std::map<SpellEnum, Spell<Type>*>::iterator it;
    for ( it = this->spellBook->begin(); it != this->spellBook->end(); ++it ) {
        delete it->second ;
    }
    std::cout << "   --- Spells' deleting from SpellBook finished. --- " << std::endl;

    delete spellBook;
    std::cout << "   --- SPELL BOOK destructed." << std::endl;
}

template <class Type>
bool SpellBook<Type>::haveSpell(SpellEnum sEnum) {
    bool result = false;

    if ( this->spellBook->find(sEnum) != this->spellBook->end() ) {
        result = true;
    }

    return result;
}

template <class Type>
void SpellBook<Type>::insertSpell(SpellEnum sEnum, Spell<Type>* spell) {
    this->spellBook->insert(std::pair<SpellEnum, Spell<Type>*>(sEnum, spell));
}

template <class Type>
const std::map<SpellEnum, Spell<Type>*>* SpellBook<Type>::getSpellBook() const {
    return this->spellBook;
}
template <class Type>
const Spell<Type>& SpellBook<Type>::getSpell(SpellEnum sEnum) const {
    return *this->spellBook->find(sEnum)->second;
}
