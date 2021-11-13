//
// Created by danil on 03.11.2021.
//
#include "../Headers/Object.h"
#include "cmath"

namespace CppObject
{
    // This is temp file for new implementations i haven't decided where to put yet

    Object Object::operator()(const Object &obj, Object *self)
    {
        if (has(Object::CallerField) && (*this)[CallerField].type == CallableType)
        {
            if (!self)
                return (*this)[CallerField](obj, this);
            return (*this)[CallerField](obj, self);
        }
        if (type != CallableType)
            throw TypeError("Object is not callable");

        return ((Callable *) container)->operator()(obj, self);
    }

    bool Object::isNone(const Object &obj)
    {
        if (obj.type == None)
            return true;
        return false;
    }

    Object Object::jsonParser(const std::string &json)
    {
        if (json[0] != '{')
            throw std::exception(); // TODO
        return {};
    }

    bool operator==(const Object &a, const Object &b)
    {

        if (a.type == Object::None || b.type == Object::None)
        {
            return false;
        }

        if (a.type != b.type)
        {
            return false;
        }

        if (a.type == Object::Int)
        {
            return *((int *) a.container) == *((int *) b.container);
        }

        if (a.type == Object::Double)
        {
            return std::fabs(*((double *) a.container) - *((double *) b.container)) < Object::Epsilon;
        }

        if (a.type == Object::String)
        {
            return *((std::string *) a.container) == *((std::string *) b.container);
        }

        if (a.type == Object::ListType)
        {
            if (a.size() != b.size())
                return false;

            for (int i  = 0; i < a.size(); i++)
            {
                if (a[i] != b[i])
                    return false;
            }
            return true;
        }

        if (a.type == Object::ObjectType)
        {
            if (a.size() != b.size())
                return false;

            auto aMap = (MapType *) a.container;
            auto bMap = (MapType *) b.container;
            for (const auto &kv : *aMap)
            {
                if (bMap->find(kv.first) == bMap->end())
                    return false;
                if (bMap->at(kv.first) != bMap->at(kv.first))
                    return false;
            }
            return true;
        }

        return false; // Callable not equal for now TODO
    }

    bool operator!=(const Object &a, const Object &b) {
        return !(a == b);
    }

    bool Object::has(const std::string &property) const
    {
        if (type != ObjectType)
        {
            return false;
        }
        return ((MapType *) container)->find(property) != ((MapType *) container)->end();
    }
}