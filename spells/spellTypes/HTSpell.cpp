#include "HTSpell.h"

HTSpell::HTSpell(SpellEnum sEnum, int power, int manaCost, const std::string& spellName)
    : Spell(sEnum, power, manaCost, spellName) {}
HTSpell::~HTSpell() {}

std::ostream& operator<<(std::ostream& out, const HTSpell* spell) {
    out << spell->Spell::getSpellName() << " spell (";
    out << "Type: Heal, ";
    out << "power: " << spell->Spell::getPower() << ", ";
    out << "mana cost: " << spell->Spell::getManaCost() << ')';
}
