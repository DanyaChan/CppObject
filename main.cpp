#include <iostream>
#include "Object.h"
using namespace MapObject;
int main() {
    Object a(List{1,2,3});
    Object none;
    Object b(MapType{{"a", 3}, {"b", 3}});
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << none << std::endl;
    a[1] = std::string("ertet");
    std::cout << a << std::endl;
}