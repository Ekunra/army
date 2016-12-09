#include "SpellBook.h"

SpellBook::SpellBook() : spellBook(new std::map<SpellEnum, Spell*>){
    spellBook->insert(std::pair<SpellEnum, Spell*>(FIREBALL, new FireBall));
    spellBook->insert(std::pair<SpellEnum, Spell*>(IMPLOSION, new Implosion));
    spellBook->insert(std::pair<SpellEnum, Spell*>(LIGHTNINGBOLT, new LightningBolt));
    spellBook->insert(std::pair<SpellEnum, Spell*>(HEAL, new Heal));
    spellBook->insert(std::pair<SpellEnum, Spell*>(BLESS, new Bless));
}
SpellBook::~SpellBook() {
    std::cout << "\n" << "--- Start deleting spells from SpellBook. --- " << std::endl;
    std::map<SpellEnum, Spell*>::iterator it;
    for (it=this->spellBook->begin(); it != this->spellBook->end(); ++it) {
        delete it->second ;
    }
    std::cout << "--- Spells' deleting from SpellBook finished. --- " << std::endl;

    delete spellBook;
    std::cout << "--- SPELL BOOK destructed." << std::endl;
}

const std::map<SpellEnum, Spell*>* SpellBook::getSpellBook() const {}
