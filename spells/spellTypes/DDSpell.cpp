#include "DDSpell.h"

DDSpell::DDSpell(SpellEnum sEnum, int power, int manaCost, const std::string& spellName)
    : Spell(sEnum, power, manaCost, spellName) {}
DDSpell::~DDSpell() {}

std::ostream& operator<<(std::ostream& out, const DDSpell* spell) {
    out << spell->Spell::getSpellName() << " spell (";
    out << "Type: DD, ";
    out << "power: " << spell->Spell::getPower() << ", ";
    out << "mana cost: " << spell->Spell::getManaCost() << ')';
}
