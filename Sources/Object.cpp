//
// Created by danil on 03.11.2021.
//
#include "../Headers/Object.h"

namespace CppObject
{
    // This is temp file for new implementations i haven't decided where to put yet

    Object Object::operator()(const Object &obj) {
        if (type != CallableType)
            throw TypeError("Object is not callable");
        return ((Callable *) container)->operator()(obj);
    }
}