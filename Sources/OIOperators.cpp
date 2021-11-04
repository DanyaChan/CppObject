//
// Created by danil on 04.11.2021.
//

#include "../Headers/Object.h"

namespace CppObject
{
    std::ostream &operator<<(std::ostream &os, const Object &obj)
    {
        if (obj.type == Object::None)
        {
            os << "None";
        } else if (obj.type == Object::Int)
        {
            os << *((int *) obj.container);
        } else if (obj.type == Object::Double)
        {
            os << *((double *) obj.container);
        } else if (obj.type == Object::String)
        {
            os << "\"" << *((std::string *) obj.container) << "\"";
        } else if (obj.type == Object::ListType)
        {
            os << '[';
            bool next = false;
            for (const auto &o : *((List *) obj.container))
            {
                if (next) os << ", ";
                os << o;
                next = true;
            }
            os << ']';
        } else if (obj.type == Object::ObjectType)
        {
            os << '{';
            bool next = false;
            for (const auto &o : *((MapType *) obj.container))
            {
                if (next) os << ", ";
                os << o.first << " : " << o.second;
                next = true;
            }
            os << '}';
        }
        return os;
    }

}