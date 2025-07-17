//
// Created by danil on 04.11.2021.
//

#include "../Headers/Object.h"

namespace CppObject
{
    std::ostream &operator<<(std::ostream &os, const Object &obj)
    {
        bool next = false;
        switch (obj.getType())
        {
            case Object::ContainedType::None:
                os << "None";
                break;
            case Object::ContainedType::Int:
                os << obj.getAs<Integer>();
                break;
            case Object::ContainedType::Float:
                os << obj.getAs<Float>();
                break;
            case Object::ContainedType::String:
                os << obj.getAs<String>();
                break;
            case Object::ContainedType::ListType:
                os << '[';
                for (const auto &o : obj.getAs<List>())
                {
                    if (next) os << ", ";
                    os << o;
                    next = true;
                }
                os << ']';
                break;
            case Object::ContainedType::MapType:
                os << '{';
                for (const auto &o : obj.getAs<MapType>())
                {
                    if (next) os << ", ";
                    os << o.first << " : " << o.second;
                    next = true;
                }
                os << '}';
                break;
            case Object::ContainedType::CallableType:
                os << "fuction()";
                break;
        }
        return os;
    }

}