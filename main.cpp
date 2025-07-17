#include <iostream>
#include "Headers/Object.h"

using namespace CppObject;

int main()
{
    Object s(MapType{});

    s[Object::CallerField] = Object([](Object *self, const Object &n) -> Object {
        if (Object::isNone(n)) {
            return 0;
        }
        Object ret(MapType{});
        ret["s"] = n;
        ret[Object::CallerField] = Object([](Object *self, const Object &n) -> Object {
            if (Object::isNone(n)) {
                return (*self)["s"];
            }
            (*self)["s"] += n;
            return (*self);
        });
        return ret;
    });

    

    Object a{MapType{}};
    a["tt"] = "123";
    a["nn"] = 123;
    a["a"] = a;
    s["list"] = Object{List{Object(1), Object("test"), a}};
    std::cout << s << std::endl;
    std::cout << s(1)(2)(3)(4)();
}