#ifndef RANDOMIZER_H
#define RANDOMIZER_H

#include <iostream>
#include <cstdlib>
#include <ctime>

class Randomizer {
    private:
        static Randomizer* instance;
    protected:
        Randomizer();
    public:
        ~Randomizer();
        static void launch();
};

#endif // RANDOMIZER_H
