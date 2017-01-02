#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

class DeadUnitException {
    public:
        std::string text;
        DeadUnitException(const std::string& text) : text(text) {}
};

class NotEnoughManaException {
    public:
        std::string text;
        NotEnoughManaException(const std::string& text) : text(text) {}
};

class NoSuchSpellException {
    public:
        std::string text;
        NoSuchSpellException(const std::string& text) : text() {}
};

#endif // EXCEPTIONS_H
