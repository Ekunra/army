#include "DDTSpell.h"

DDTSpell::DDTSpell(SpellEnum sEnum, int power, int manaCost, const std::string& spellName)
    : Spell(sEnum, power, manaCost, spellName) {}
DDTSpell::~DDTSpell() {
    std::cout << "   --- DDTSpell destructed" << std::endl;
}

std::ostream& operator<<(std::ostream& out, const DDTSpell* spell) {
    out << "\033[31m" << "   * " << "\033[0m" << spell->Spell::getSpellName() << " spell (";
    out << "Type: " << "\033[31m" << "DD" << "\033[0m" << ", ";
    out << "power: " << spell->Spell::getPower() << ", ";
    out << "\033[34m" << "mana cost" << "\033[0m" << ": " << spell->Spell::getManaCost() << ')';
}
