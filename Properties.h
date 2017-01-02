#ifndef PROPERTIES_H
#define PROPERTIES_H

enum class UnitEnum {
    DEFAULT,

    SOLDIER,
    ROGUE,
    BERSERKER,
    WEREWOLF,
    VAMPIRE,

    WIZARD,
    HEALER,
    PRIEST,
    WARLOCK,
    NECROMANCER,

    DEMON,
    WOLF
};

enum class Hp {
    SOLDIER = 100,
    ROGUE = 80,
    WEREWOLF = 90,
    VAMPIRE = 110,
    BERSERKER = 105,
    WIZARD = 60,
    HEALER = 40,
    PRIEST = 60,
    WARLOCK = 80,
    NECROMANCER = 40
};

enum class Dmg {
    SOLDIER = 20,
    ROGUE = 25,
    WEREWOLF = 20,
    VAMPIRE = 25,
    BERSERKER = 30,
    WIZARD = 10,
    HEALER = 10,
    PRIEST = 10,
    WARLOCK = 15,
    NECROMANCER = 15
};

enum class Mana {
    WIZARD = 200,
    HEALER = 150,
    PRIEST = 120,
    WARLOCK = 80,
    NECROMANCER = 100
};

enum class SPower {
    FIREBALL = 25,
    IMPLOSION = 20,
    LIGHTNINGBOLT = 30,
    HEAL = 40,
    BLESS = 500,
    MANAPORTION = 40
};

enum class SCost {
    FIREBALL = 50,
    IMPLOSION = 40,
    LIGHTNINGBOLT = 60,
    HEAL = 40,
    BLESS = 100,
    MANAPORTION = 20
};

enum class Coef {
    WIZARD,
    HEALER,
    PRIEST,
    WARLOCK
};

#endif // PROPERTIES_H
