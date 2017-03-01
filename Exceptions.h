#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <iostream>
#include "macro_color.cpp"

class ArmyException {
    public:
        std::string text;
        ArmyException(const std::string& text) : text(text) {}

        void show() {
            std::cout << FO_B_L_RED << "   - [EXCEPION] " << text << FO_RESET << std::endl;
        }
};

class DeadUnitException : public ArmyException {
    public:
        std::string text;
        DeadUnitException(const std::string& text) : ArmyException(text) {}
};

class NotEnoughManaException : public ArmyException {
    public:
        std::string text;
        NotEnoughManaException(const std::string& text) : ArmyException(text) {}
};

class NoSuchSpellException : public ArmyException {
    public:
        std::string text;
        NoSuchSpellException(const std::string& text) : ArmyException(text) {}
};

#endif // EXCEPTIONS_H
