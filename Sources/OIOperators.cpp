//
// Created by danil on 04.11.2021.
//

#include "../Headers/Object.h"

namespace CppObject
{
    std::ostream &operator<<(std::ostream &os, const Object &obj)
    {
        bool next = false;
        switch (obj.type)
        {
            case Object::None:
                os << "None";
                break;
            case Object::Int:
                os << *((int *) obj.container);
                break;
            case Object::Double:
                os << *((double *) obj.container);
                break;
            case Object::String:
                os << "\"" << *((std::string *) obj.container) << "\"";
                break;
            case Object::ListType:
                os << '[';
                for (const auto &o : *((List *) obj.container))
                {
                    if (next) os << ", ";
                    os << o;
                    next = true;
                }
                os << ']';
                break;
            case Object::ObjectType:
                os << '{';
                for (const auto &o : *((MapType *) obj.container))
                {
                    if (next) os << ", ";
                    os << o.first << " : " << o.second;
                    next = true;
                }
                os << '}';
                break;
            case Object::CallableType:
                os << "fuction()";
                break;
        }
        return os;
    }

}