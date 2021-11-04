//
// Created by danil on 03.11.2021.
//
#include <string>
#include <unordered_map>
#include <set>
#include <vector>
#include <exception>
#include <ostream>

#ifndef OBJECT_OBJECT_H
#define OBJECT_OBJECT_H

namespace MapObject
{
    class Object;
    typedef std::vector<Object> List;
    typedef std::unordered_map<std::string, Object> MapType;

    class Exception : std::exception
    {
        virtual std::string what() = 0;
    };

    class TypeError : Exception
    {
    public:
        explicit TypeError(const std::string &s)
        {
            info = s;
        }

        virtual std::string what() override
        {
            return info;
        }

    private:
        std::string info;
    };

    class Object
    {
    public:
        Object();

        Object(int);

        Object(double);

        Object(const std::string &);

        explicit Object(const std::vector<Object> &);

        explicit Object(const std::unordered_map<std::string, Object> &);

        Object(const Object &);

        static void *allocateObject(const Object &);

        ~Object();


        operator int();

        operator double();

        operator std::string();

        Object &operator[](const std::string &);

        Object &operator[](int);

        Object &operator=(const Object &a);

        Object &operator+=(const Object &a);

        Object &operator-=(const Object &a);

        Object &operator*=(const Object &a);

        Object &operator/=(const Object &a);

        friend Object operator+(const Object &a, const Object &b);

        friend Object operator-(const Object &a, const Object &b);

        friend Object operator/(const Object &a, const Object &b);

        friend Object operator*(const Object &a, const Object &b);

        friend std::ostream &operator<<(std::ostream &os, const Object &obj)
        {
            if (obj.type == None) {
                os << "None";
            }
            else if (obj.type == Int) {
                os << *((int *)obj.container);
            } else if (obj.type == Double) {
                os << *((double *)obj.container);
            } else if (obj.type == String) {
                os << *((std::string *)obj.container);
            } else if (obj.type == ListType) {
                os << '[';
                bool next = false;
                for (const auto &o : *((List*) obj.container))
                {
                    if (next) os << ", ";
                    os << o;
                    next = true;
                }
                os << ']';
            } else if (obj.type == ObjectType) {
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
        }

        Object &operator++();

        Object &operator--();

        Object operator++(int);

        Object operator--(int);


    private:

        enum ContainedType : char
        {
            None,
            Int,
            String,
            Double,
            ObjectType,
            ListType
        };
        char type;
        mutable void *container;
    };
}
#endif //OBJECT_OBJECT_H
