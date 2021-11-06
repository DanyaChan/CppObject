#include <iostream>
#include "Headers/Object.h"

using namespace CppObject;

int main()
{
    Object a = "test", b = 1;
    a+="12";
    std::cout << ++b << std::endl;
    Object obj(MapType{});
    obj["string"] = a;
    obj["Int"] = b;
    obj["double"] = 3.14;
    obj["list"] = Object(List{1, 2, "test"});

    Object obj1(MapType{});
    obj1["string"] = a;
    obj1["Int"] = b;
    obj1["double"] = 3.14;
    obj1["list"] = Object(List{1, 2, "test"});


    std::cout << (obj == obj1);
}