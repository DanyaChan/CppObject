//
// Created by danil on 04.11.2021.
//

#include "../Headers/Object.h"

namespace CppObject
{

    Object::operator Integer() const
    {
        if (getType() != ContainedType::Int)
            throw TypeError("Object is not Int");
        return getAs<Integer>();
    }

    Object::operator Float() const
    {
        if (getType() != ContainedType::Float)
            throw TypeError("Object is not Double");
        return getAs<Float>();
    }

    Object::operator String() const
    {
        if (getType() != ContainedType::String)
            throw TypeError("Object is not String");
        return getAs<String>();
    }

    Object &Object::operator[](const std::string &s)
    {
        if (getType() != ContainedType::MapType)
            throw TypeError("Object does not contain" + s);
        return getAs<MapType>()[s];
    }

    Object &Object::operator[](int i)
    {
        if (getType() != ContainedType::ListType)
            throw TypeError("Object is not a list");
        if (i < 0) {
            i = getAs<List>().size() + i;
        }
        if (i < 0 || i >= getAs<List>().size())
            throw OutOfRange("Index is out of range");
        return getAs<List>()[i];
    }

    const Object &Object::operator[](int i) const
    {
        if (getType() != ContainedType::ListType)
            throw TypeError("Object is not a list");
        if (i < 0) {
            i = getAs<List>().size() + i;
        }
        if (i < 0 || i >= getAs<List>().size())
            throw OutOfRange("Index is out of range");
        return getAs<List>()[i];
    }

    const Object &Object::operator[](const std::string &s) const
    {
        if (getType() != ContainedType::MapType)
            throw TypeError("Object does not contain" + s);
        return getAs<MapType>().at(s);
    }

    size_t Object::size() const
    {
        if (getType() == ContainedType::ListType)
            return getAs<List>().size();
        if (getType() == ContainedType::MapType)
            return getAs<MapType>().size();
        throw TypeError("Size is not supported for this type");
    }
}
