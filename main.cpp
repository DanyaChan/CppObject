#include <iostream>
#include "Headers/Object.h"

using namespace CppObject;

int main()
{
    // Object list = {"test", 123, "rrrr"};
    Object list = {"test", 123, "rrrr", Object{
        {"test", 1}, {"test1", 3}
    }};
    Object f{[](Object* self, const Object& p) -> Object {
        return 2 + p;
    }};
    std::cout << list[3]["test1"] + f(2);
}