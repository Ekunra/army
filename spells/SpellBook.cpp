#include "SpellBook.h"

SpellBook::SpellBook() : spellBook(new std::map<SpellEnum, Spell*>){
}
SpellBook::~SpellBook() {
    std::cout << "   --- Start deleting spells from SpellBook. --- " << std::endl;
    std::map<SpellEnum, Spell*>::iterator it;
    for (it=this->spellBook->begin(); it != this->spellBook->end(); ++it) {
        delete it->second ;
    }
    std::cout << "   --- Spells' deleting from SpellBook finished. --- " << std::endl;

    delete spellBook;
    std::cout << "   --- SPELL BOOK destructed." << std::endl;
}

bool SpellBook::haveSpell(SpellEnum sEnum) {
    bool result = false;

    if ( this->spellBook->find(sEnum) != this->spellBook->end() ) {
        result = true;
    }

    return result;
}

void SpellBook::insertSpell(SpellEnum sEnum, Spell* spell) {
    this->spellBook->insert(std::pair<SpellEnum, Spell*>(sEnum, spell));
}

const std::map<SpellEnum, Spell*>* SpellBook::getSpellBook() const {
    return this->spellBook;
}
const Spell* SpellBook::getSpell(SpellEnum sEnum) const {
    return this->spellBook->find(sEnum)->second;
}
