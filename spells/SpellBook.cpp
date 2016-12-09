#include "SpellBook.h"

SpellBook::SpellBook() : spellBook(new std::map<SpellEnum, Spell*>){
    
}
SpellBook::~SpellBook() {
    delete spellBook;
}

const std::map<SpellEnum, Spell*>* SpellBook::getSpellBook() const {}
