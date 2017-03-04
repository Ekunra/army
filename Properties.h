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
    WOLF,

    EVILSPIRIT,
    ALIVE
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

enum class TakeDamageCoef { // Divides by 100 while initialization.
    DEFAULT = 100,

    SOLDIER = 100,
    ROGUE = 100,
    BERSERKER = 100,
    WEREWOLF = 100,
    VAMPIRE = 100,

    WIZARD = 100,
    HEALER = 100,
    PRIEST = 100,
    WARLOCK = 100,
    NECROMANCER = 100,

    DEMON = 100,
    WOLF = 100,

    EVILSPIRIT = 100,
    ALIVE = 100
};

enum class TakeMagicDamageCoef { // Divided by 100 while initialization.
    DEFAULT = 100,

    SOLDIER = 100,
    ROGUE = 100,
    BERSERKER = 100,
    WEREWOLF = 100,
    VAMPIRE = 100,

    WIZARD = 100,
    HEALER = 100,
    PRIEST = 100,
    WARLOCK = 100,
    NECROMANCER = 100,

    DEMON = 100,
    WOLF = 200,

    EVILSPIRIT,
    ALIVE
};

enum class Mp {
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
    MANAPORTION = 40,
    MANADRAIN = 50
};

enum class SCost {
    FIREBALL = 50,
    IMPLOSION = 40,
    LIGHTNINGBOLT = 60,
    HEAL = 40,
    BLESS = 100,
    MANAPORTION = 20,
    MANADRAIN = 20
};

enum class DDTMagicCoef { // Divided by 100 while initialization.
    WIZARD = 100,
    HEALER = 50,
    PRIEST = 50,
    NECROMANCER = 100
};

enum class HTMagicCoef { // Divided by 100 while initialization.
    WIZARD = 50,
    HEALER = 100,
    PRIEST = 100,
    NECROMANCER = 50
};

enum class MTMagicCoef { // Divided by 100 while initialization.
    WIZARD = 100,
    HEALER = 100,
    PRIEST = 100,
    NECROMANCER = 100
};

enum class DMTMagicCoef { // Divided by 100 while initialization.
    WIZARD = 150,
    HEALER = 100,
    PRIEST = 100,
    NECROMANCER = 100
};

enum class VampireDrinkBlood { // Divided by 100 while calculation
    COEF = 50
};

enum class FieldType {
    HEALTH,
    MANA,
    DEFAULT
};

#endif // PROPERTIES_H
