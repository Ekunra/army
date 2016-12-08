#include "FireBall.h"

FireBall::FireBall(SpellEnum sEnum, int power, int manaCost, const std::string& spellName)
    : Spell(sEnum, power, manaCost, spellName) {}
FireBall::~FireBall() {}
