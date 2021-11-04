#include <iostream>
#include "Headers/Object.h"

using namespace CppObject;


int main()
{
    Object a = "test", b = 1;
    Object c(MapType{});
    c["string"] = a;
    c["Int"] = b;
    c["double"] = 3.14;
    c["list"] = Object(List{1, 2, "test"});
    c["object"] = Object(c);
    std::cout << c << std::endl;
    std::cout << a + Object(" ") +  a;
    std::cout << a + Object(1);
}