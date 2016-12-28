#ifndef LIMITEDFIELD_H
#define LIMITEDFIELD_H

#include <iostream>

template <class Type>
class LimitedField {
    protected:
        Type* value;
        Type* limit;

    public:
        LimitedField(Type value);
        ~LimitedField();

        const Type getValue() const;
        const Type getLimit() const;
};

template <class Type>
std::ostream& operator<<(std::ostream& out, const LimitedField<Type>& field);

#endif // LIMITEDFIELD_H
