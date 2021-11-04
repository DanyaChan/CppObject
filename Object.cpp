//
// Created by danil on 03.11.2021.
//

#include "Object.h"

using namespace MapObject;

Object::Object()
{
    type = None;
}


Object::Object(int n) :
        type(Int),
        container((void *) new int(n))
{}

Object::Object(double d) :
        type(Double),
        container((void *) new double(d))
{}

Object::Object(const std::string &s) :
        type(String),
        container((void *) new std::string(s))
{}

Object::Object(const std::vector<Object> &list) :
        type(ListType),
        container((void *) new std::vector<Object>(list))
{}

Object::Object(const MapType &map) :
        type(ObjectType),
        container((void *) new MapType(map))
{

}

Object::Object(const Object &obj) :
        type(obj.type),
        container(allocateObject(obj))
{

}


void *Object::allocateObject(const Object &obj)
{
    switch (obj.type)
    {
        case None:
            return nullptr;
        case Int:
            return new int(*((int *) obj.container));
        case Double:
            return new double(*((double *) obj.container));
        case String:
            return (void *) new std::string(*((std::string *) obj.container));
        case ObjectType:
            return (void *) new MapType(
                    *((MapType *) obj.container));
        case ListType:
            return (void *) new std::vector<Object>(*((std::vector<Object> *) obj.container));
    }
}

Object::~Object()
{
    switch (type)
    {
        case None:
            return;
        case Int:
            delete (int *) container;
            break;
        case Double:
            delete (double *) container;
            break;
        case String:
            delete (std::string *) container;
            break;
        case ObjectType:
            delete (MapType *) container;
            break;
        case ListType:
            delete (std::vector<Object> *) container;
            break;
    }
}

Object &Object::operator=(const Object &a)
{
    switch (type)
    {
        case None:
            break;
        case Int:
            delete (int *) container;
            break;
        case Double:
            delete (double *) container;
            break;
        case String:
            delete (std::string *) container;
            break;
        case ObjectType:
            delete (MapType *) container;
            break;
        case ListType:
            delete (std::vector<Object> *) container;
            break;
    }
    type = a.type;
    container = allocateObject(a);
}

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

Object operator+(const Object &a, const Object &b)
{}

Object operator-(const Object &a, const Object &b)
{}

Object operator/(const Object &a, const Object &b)
{}

Object operator*(const Object &a, const Object &b)
{}

