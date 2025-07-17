//
// Created by danil on 03.11.2021.
//
#include "../Headers/Object.h"
#include "cmath"

namespace CppObject
{
    // This is temp file for new implementations i haven't decided where to put yet

    Object::ContainedType Object::getType() const {
        return static_cast<ContainedType>(container.index());
    }

    Object Object::operator()(const Object &obj)
    {
        if (has(Object::CallerField) && (*this)[CallerField].getType() == ContainedType::CallableType)
        {
            return (*this)[CallerField].getAs<Callable>()(this, obj);
        }
        if (getType() != ContainedType::CallableType)
            throw TypeError("Object is not callable");

        return getAs<Callable>()(this, obj);
    }

    bool Object::isNone(const Object &obj)
    {
        if (obj.getType() == ContainedType::None)
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

        if (a.getType() == Object::ContainedType::None || b.getType() == Object::ContainedType::None)
        {
            return false;
        }

        if (a.getType() != b.getType())
        {
            return false;
        }

        if (a.getType() == Object::ContainedType::Int)
        {
            return a.getAs<Integer>() == b.getAs<Integer>();
        }

        if (a.getType() == Object::ContainedType::Float)
        {
            return std::fabs(a.getAs<Float>() - b.getAs<Float>()) < Object::Epsilon;
        }

        if (a.getType() == Object::ContainedType::String)
        {
            return a.getAs<String>() == b.getAs<String>();
        }

        if (a.getType() == Object::ContainedType::ListType)
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

        if (a.getType() == Object::ContainedType::MapType)
        {
            if (a.size() != b.size())
                return false;

            auto& aMap = a.getAs<MapType>();
            auto& bMap = b.getAs<MapType>();
            for (const auto &kv : aMap)
            {
                if (bMap.find(kv.first) == bMap.end())
                    return false;
                if (bMap.at(kv.first) != bMap.at(kv.first))
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
        if (getType() != ContainedType::MapType)
        {
            return false;
        }
        return getAs<MapType>().find(property) != getAs<MapType>().end();
    }
}