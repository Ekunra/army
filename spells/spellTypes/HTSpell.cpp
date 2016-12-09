#include "HTSpell.h"

HTSpell::HTSpell(SpellEnum sEnum, int power, int manaCost, const std::string& spellName)
    : Spell(sEnum, power, manaCost, spellName) {}
HTSpell::~HTSpell() {
    std::cout << "   --- HTSpell destructed" << std::endl;
}

std::ostream& operator<<(std::ostream& out, const HTSpell* spell) {
    out << "\033[32m" << "   * " << "\033[0m" << spell->Spell::getSpellName() << " spell (";
    out << "Type: " << "\033[32m" << "HL" << "\033[0m" << ", ";
    out << "power: " << spell->Spell::getPower() << ", ";
    out << "\033[34m" << "mana cost" << "\033[0m" << ": " << spell->Spell::getManaCost() << ')';
}
