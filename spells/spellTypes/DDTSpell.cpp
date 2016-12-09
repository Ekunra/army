#include "DDTSpell.h"

DDTSpell::DDTSpell(SpellEnum sEnum, int power, int manaCost, const std::string& spellName)
    : Spell(sEnum, power, manaCost, spellName) {}
DDTSpell::~DDTSpell() {}

std::ostream& operator<<(std::ostream& out, const DDTSpell* spell) {
    out << spell->Spell::getSpellName() << " spell (";
    out << "Type: DD, ";
    out << "power: " << spell->Spell::getPower() << ", ";
    out << "mana cost: " << spell->Spell::getManaCost() << ')';
}
