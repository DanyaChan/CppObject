//
// Created by danil on 04.11.2021.
//

#include "../Headers/Object.h"

namespace CppObject
{
        Object::Object() {}

        Object::Object(Integer n) : container(n)
        {
        }

        Object::Object(Float d) : container(d)
        {
        }

        Object::Object(const String &s) : container(s)
        {
        }

        Object::Object(const List &list) : container(list)
        {
        }

        Object::Object(const std::initializer_list<Object> &list) : container(nullptr) {
            List l_candidate;
            MapType m_candidate;
            for (const auto& value: list) {
                if (l_candidate.empty() && value.getType() == ContainedType::ListType && value.size() == 2 && value[0].getType() == ContainedType::String) {
                    m_candidate[value[0].getAs<String>()] = value[1];
                }
                else {
                    l_candidate.push_back(value);
                }
            }
            if (!l_candidate.empty()) {
                for (auto&& v: m_candidate) {
                    l_candidate.push_back({v.first, v.second});
                }
                container = l_candidate;
                return;
            }
            container = m_candidate;
        }
        // Object::Object(const std::initializer_list<std::pair<String, Object>> &m) : container(MapType{}) {
        //     for (const auto& p: m) {
        //         getAs<MapType>()[p.first] = p.second;
        //     }
        // }

        Object::Object(const MapType &map) : container(map)
        {
        }

        Object::Object(const Object &obj) : container(obj.container)
        {
        }

        Object::~Object() {}

        Object &Object::operator=(const Object &a)
        {
                container = a.container;
                return *this;
        }

        Object &Object::operator=(const char *s)
        {
                return operator=(Object(s));
        }
}