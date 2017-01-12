#include "Spell.h"

Spell::Spell(SpellEnum sEnum, int power, int manaCost, const std::string& spellName)
    : sEnum(sEnum), power(new int(power)), manaCost(new int(manaCost)), spellName(new std::string(spellName)) {
    std::cout << "         + " << this->getSpellName() << "'s Spell:: created" << std::endl;
}
Spell::~Spell() {
    std::cout << "         - " << this->getSpellName() << "'s Spell:: destructed" << std::endl;
}

const SpellEnum Spell::getSEnum() const {
    return this->sEnum;
}
const int Spell::getPower() const {
    return *this->power;
}
const int Spell::getManaCost() const {
    return *this->manaCost;
}
const std::string& Spell::getSpellName() const {
    return *this->spellName;
}

std::ostream& operator<<(std::ostream& out, const Spell* spell) {
    out << spell->getSpellName() << " spell (";
    out << "power: " << spell->getPower() << ", ";
    out << "mana cost: " << spell->getManaCost() << ')';
    return out;
}
