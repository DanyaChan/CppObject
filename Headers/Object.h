//
// Created by danil on 03.11.2021.
//


#ifndef OBJECT_OBJECT_H
#define OBJECT_OBJECT_H

#include <string>
#include <unordered_map>
#include <set>
#include <vector>
#include <exception>
#include <ostream>

namespace CppObject
{

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

    class Object;

    typedef std::vector<Object> List;
    typedef std::unordered_map<std::string, Object> MapType;

    class Object
    {
    public:
        Object();

        Object(int);

        Object(double);

        Object(const char *s) : Object(std::string(s))
        {}

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

        Object &operator[](const char s[]) {
            return operator[](std::string(s));
        }

        const Object &operator[](const std::string &) const;

        const Object &operator[](const char s[]) const {
            return operator[](std::string(s));
        }

        Object &operator[](int);

        const Object &operator[](int) const;

        Object &operator=(const Object &a);

        Object &operator+=(const Object &a);

        Object &operator-=(const Object &a);

        Object &operator*=(const Object &a);

        Object &operator/=(const Object &a);

        friend std::ostream &operator<<(std::ostream &os, const Object &obj);

        friend Object operator+(const Object &a, const Object &b);

        friend Object operator-(const Object &a, const Object &b);

        friend Object operator/(const Object &a, const Object &b);

        friend Object operator*(const Object &a, const Object &b);

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
        void *container;
    };
}


#endif //OBJECT_OBJECT_H
