#include <iostream>
#include "Headers/Object.h"

using namespace CppObject;

int main()
{
    Object s(MapType{});

    s[Object::CallerField] = Object([](const Object &n, Object *self) -> Object {
        if (Object::isNone(n)) {
            return 0LL;
        }
        Object ret(MapType{});
        ret["s"] = n;
        ret[Object::CallerField] = Object([](const Object &n, Object *self) -> Object {
            if (Object::isNone(n)) {
                return (*self)["s"];
            }
            (*self)["s"] += n;
            return (*self);
        });
        return ret;
    });
    std::cout << s(1)(4)(2)();
}