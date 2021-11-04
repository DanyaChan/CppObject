//
// Created by danil on 04.11.2021.
//

#include "../Headers/Object.h"

namespace CppObject
{

    Object::operator int()
    {
        if (type != Int)
            throw TypeError("Object is not Int");
        return *((int *) container);
    }

    Object::operator double()
    {
        if (type != Double)
            throw TypeError("Object is not Double");
        return *((double *) container);
    }

    Object::operator std::string()
    {
        if (type != String)
            throw TypeError("Object is not String");
        return *((std::string *) container);
    }

    Object &Object::operator[](const std::string &s)
    {
        if (type != ObjectType)
            throw TypeError("Object does not contain" + s);
        return ((MapType *) container)->operator[](s);
    }

    Object &Object::operator[](int i)
    {
        if (type != ListType)
            throw TypeError("Object is not a list");
        return ((List *) container)->operator[](i);
    }

    const Object &Object::operator[](int i) const
    {
        if (type != ListType)
            throw TypeError("Object is not a list");
        return ((List *) container)->operator[](i);
    }

    const Object &Object::operator[](const std::string &s) const
    {
        if (type != ObjectType)
            throw TypeError("Object does not contain" + s);
        return ((MapType *) container)->operator[](s);
    }

}
