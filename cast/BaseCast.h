#ifndef BASECAST_H
#define BASECAST_H

#include <iostream>
#include "../debug.h"
#include "../macro_color.cpp"
#include "../Properties.h"

template <class Type>
class BaseCast {
    public:
        BaseCast();
        virtual ~BaseCast();

        virtual void action();
};

#endif // BASECAST_H
