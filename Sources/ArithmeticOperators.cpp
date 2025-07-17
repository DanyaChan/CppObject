//
// Created by danil on 04.11.2021.
//

#include "../Headers/Object.h"

namespace CppObject
{

    Object operator+(const Object &a, const Object &b)
    {
        Object ret(a);
        return ret += b;
    }

    Object operator-(const Object &a, const Object &b)
    {
        Object ret(a);
        return ret -= b;
    }

    Object operator/(const Object &a, const Object &b)
    {
        Object ret(a);
        return ret /= b;
    }

    Object operator*(const Object &a, const Object &b)
    {
        Object ret(a);
        return ret *= b;
    }

    Object &Object::operator+=(const Object &a)
    {
        if (getType() == ContainedType::Int)
        {
            if (a.getType() == ContainedType::Int)
            {
                getAs<Integer>() += a.getAs<Integer>();
            }
            else if (a.getType() == ContainedType::Float)
            {
                container = (getAs<Integer>() + a.getAs<Float>());
            }
            else
            {
                throw TypeError("No viable getType() conversion.");
            }
        }
        else if (getType() == ContainedType::Float)
        {
            if (a.getType() == ContainedType::Int)
            {
                getAs<Float>() += a.getAs<Integer>();
            }
            else if (a.getType() == ContainedType::Float)
            {
                getAs<Integer>() += a.getAs<Float>();
            }
            else
            {
                throw TypeError("No viable getType() conversion.");
            }
        }
        else if (getType() == ContainedType::String)
        {
            if (a.getType() == ContainedType::String)
            {
                getAs<String>() += a.getAs<String>();
            }
            else
            {
                throw TypeError("No viable getType() conversion.");
            }
        }
        else
        {
            throw TypeError("Unsupported operation");
        }
        return *this;
    }

    Object &Object::operator-=(const Object &a)
    {
        if (getType() == ContainedType::Int)
        {
            if (a.getType() == ContainedType::Int)
            {
                getAs<Integer>() -= a.getAs<Integer>();
            }
            else if (a.getType() == ContainedType::Float)
            {
                container = (getAs<Integer>() - a.getAs<Float>());
            }
            else
            {
                throw TypeError("No viable getType() conversion.");
            }
        }
        else if (getType() == ContainedType::Float)
        {
            if (a.getType() == ContainedType::Int)
            {
               getAs<Float>() -= getAs<Integer>();
            }
            else if (a.getType() == ContainedType::Float)
            {
                getAs<Float>() -= getAs<Float>();
            }
            else
            {
                throw TypeError("No viable getType() conversion.");
            }
        }
        else
        {
            throw TypeError("Unsupported operation");
        }
        return *this;
    }

    Object &Object::operator*=(const Object &a)
    {
        if (getType() == ContainedType::Int)
        {
            if (a.getType() == ContainedType::Int)
            {
                getAs<Integer>() *= a.getAs<Integer>();
            }
            else if (a.getType() == ContainedType::Float)
            {
                container = getAs<Integer>() * a.getAs<Float>();
            }
            else
            {
                throw TypeError("No viable type conversion.");
            }
        }
        else if (getType() == ContainedType::Float)
        {
            if (a.getType() == ContainedType::Int)
            {
                getAs<Float>() *= a.getAs<Integer>();
            }
            else if (a.getType() == ContainedType::Float)
            {
                getAs<Float>() *= a.getAs<Float>();
            }
            else
            {
                throw TypeError("No viable type conversion.");
            }
        }
        else
        {
            throw TypeError("Unsupported operation");
        }
        return *this;
    }

    Object &Object::operator/=(const Object &a)
    {
        if (getType() == ContainedType::Int)
        {
            if (a.getType() == ContainedType::Int)
            {
                if (a.getAs<Integer>() == 0) throw std::runtime_error("Div by zero");
                getAs<Integer>() /= a.getAs<Integer>();
            }
            else if (a.getType() == ContainedType::Float)
            {
                container = getAs<Integer>() / a.getAs<Float>();
            }
            else
            {
                throw TypeError("No viable getType() conversion.");
            }
        }
        else if (getType() == ContainedType::Float)
        {
            if (a.getType() == ContainedType::Int)
            {
                getAs<Float>() /= a.getAs<Integer>();
            }
            else if (a.getType() == ContainedType::Float)
            {
                getAs<Float>() /= a.getAs<Float>();
            }
            else
            {
                throw TypeError("No viable getType() conversion.");
            }
        }
        else
        {
            throw TypeError("Unsupported operation");
        }
        return *this;
    }

    Object &Object::operator++()
    {
        if (getType() != ContainedType::Int)
            throw TypeError("No increment operator fo this getType()");
        getAs<Integer>()++;
        return *this;
    }

    Object &Object::operator--()
    {
        if (getType() != ContainedType::Int)
            throw TypeError("No dencrement operator fo this getType()");
        getAs<Integer>()++;
        return *this;
    }

    Object Object::operator++(int)
    {
        if (getType() != ContainedType::Int)
            throw TypeError("No increment operator fo this getType()");
        Object copy = *this;
        getAs<Integer>()++;
        return copy;
    }

    Object Object::operator--(int)
    {
        if (getType() != ContainedType::Int)
            throw TypeError("No dencrement operator fo this getType()");
        Object copy = *this;
        getAs<Integer>()--;
        return copy;
    }
}