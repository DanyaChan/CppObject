//
// Created by danil on 03.11.2021.
//
#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
#include <set>
#include <vector>
#include <exception>
#include <ostream>
#include <functional>
#include <variant>
#include <memory>

namespace CppObject
{

    class Exception : std::exception
    {
        virtual std::string what() = 0;
    };

    class OutOfRange : Exception
    {
    public:
        explicit OutOfRange(const std::string &s)
        {
            info = s;
#ifdef CPPOBJECT_LOGGING
            std::cout << s << std::endl;
#endif
        }

        virtual std::string what() override
        {
            return info;
        }

    private:
        std::string info;
    };

    class TypeError : Exception
    {
    public:
        explicit TypeError(const std::string &s)
        {
            info = s;
#ifdef CPPOBJECT_LOGGING
            std::cout << s << std::endl;
#endif
        }

        virtual std::string what() override
        {
            return info;
        }

    private:
        std::string info;
    };

    class Object;

    using Null = nullptr_t;
    using Integer = long long;
    using String = std::string;
    using Float = double;

    typedef std::vector<Object> List;
    typedef std::unordered_map<std::string, Object> MapType;
    typedef std::function<Object(const Object &, Object *)> Callable;

    template <class T>
    using Ptr = std::unique_ptr<T>;

    class Object
    {
    public:
        Object();

        Object(int a) : container((long long) a){}
        Object(Integer);

        Object(Float);

        Object(const char *s) : Object(String(s))
        {}

        Object(const String &);

        explicit Object(const List &);

        explicit Object(const MapType &);

        explicit Object(const Callable &f);

        Object(const Object &);

        static void *allocateObject(const Object &);

        ~Object();


        explicit operator Integer();

        explicit operator Float();

        explicit operator String();

        Object &operator[](const String &);

        Object &operator[](const char s[])
        {
            return operator[](String(s));
        }

        const Object &operator[](const String &) const;

        const Object &operator[](const char s[]) const
        {
            return operator[](String(s));
        }

        Object &operator[](int);

        const Object &operator[](int) const;

        Object &operator=(const Object &a);

        Object &operator=(const char* s);

        Object &operator+=(const Object &a);

        Object &operator-=(const Object &a);

        Object &operator*=(const Object &a);

        Object &operator/=(const Object &a);

        friend std::ostream &operator<<(std::ostream &os, const Object &obj);

        // arithmetic

        friend Object operator+(const Object &a, const Object &b);

        friend Object operator-(const Object &a, const Object &b);

        friend Object operator/(const Object &a, const Object &b);

        friend Object operator*(const Object &a, const Object &b);

        // comp operators

        friend bool operator!=(const Object &a, const Object &b);

        friend bool operator==(const Object &a, const Object &b);

        friend bool operator<(const Object &a, const Object &b);

        friend bool operator>(const Object &a, const Object &b);

        friend bool operator<=(const Object &a, const Object &b);

        friend bool operator>=(const Object &a, const Object &b);


        Object &operator++();

        Object &operator--();

        Object operator++(int);

        Object operator--(int);

        Object operator()(const Object &obj = Object{}, Object *self = nullptr);

        static bool isNone(const Object &obj);

        bool has(const std::string &property) const;

        static Object jsonParser(const std::string &json);

        constexpr static const char CallerField[] = "__calley";

        size_t size() const;

        

    private:

        enum class ContainedType
        {
            None = 0,
            Int,
            String,
            Float,
            MapType,
            ListType,
            CallableType
        };

        template <class Type>
        Type& getAs() {
            return std::get<Type>(container);
        }
        template <class Type>
        const Type& getAs() const {
            return std::get<Type>(container);
        }
        ContainedType getType() const;

        static Object jsonParser(const char *begin, const char *end);

        constexpr static double Epsilon = 1e-12; // set to negative if u dont wanna == double comparation;

        std::variant<Null, Integer, String, Float, MapType, List, Callable> container{nullptr};
    };
}
