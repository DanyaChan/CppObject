#include <iostream>
#include "Headers/Object.h"

using namespace CppObject;

int main()
{
    Object a = "test", b = 1;
    a+="12";
    Object obj(MapType{});
    obj["string"] = a;
    obj["Int"] = b;
    obj["double"] = 3.14;
    obj["list"] = Object(List{1, 2, "test"});
    obj["object"] = Object(obj);

    Object f ([](const Object &o)->Object{
        std::cout << o << std::endl;
        std::cout << Object("Hello world") << std::endl;
        return {};
    });

    f(Object(
            List{"arg1", "arg2", "arg3"}
            ));

    obj["function"] = f;
    obj["None"];
    obj["function"](a);
    std::cout << obj;
}