//
// Created by danil on 04.11.2021.
//

#include "../Headers/Object.h"

namespace CppObject
{
    Object::Object() {}


    Object::Object(Integer n) :
            container(n)
    {}

    Object::Object(Float d) :
            container(d)
    {}

    Object::Object(const std::string &s) :
            container(s)
    {}

    Object::Object(const List &list) :
            container(list)
    {}

    Object::Object(const MapType &map) :
            container(map)
    {

    }

    Object::Object(const Object &obj) :
            container(obj.container)
    {

    }

    Object::Object(const Callable &f) :
            container(f)
    {

    }

    Object::~Object() {}

    Object &Object::operator=(const Object &a)
    {
        container = a.container;
        return *this;
    }

    Object &Object::operator=(const char *s)
    {
        return operator=(Object(s));
    }
}