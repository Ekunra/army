#include "HealSpell.h"

HealSpell::HealSpell(SpellEnum sEnum, int power, int manaCost, const std::string& spellName)
    : Spell(sEnum, power, manaCost, spellName) {}
HealSpell::~HealSpell() {}

std::ostream& operator<<(std::ostream& out, const HealSpell* spell) {
    out << spell->Spell::getSpellName() << " spell (";
    out << "Type: Heal, ";
    out << "power: " << spell->Spell::getPower() << ", ";
    out << "mana cost: " << spell->Spell::getManaCost() << ')';
}
