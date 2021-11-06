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
        if (type == Int)
        {
            if (a.type == Int)
            {
                *((int *) container) += *((int *) a.container);
            } else if (a.type == Double)
            {
                *this = Object(*((int *) container) + *((double *) a.container));
            } else
            {
                throw TypeError("No viable type conversion.");
            }
        }
        else if (type == Double)
        {
            if (a.type == Int)
            {
                *((double *) container) += (double) *((int *) a.container);
            } else if (a.type == Double)
            {
                *((double *) container) += *((double *) a.container);
            } else
            {
                throw TypeError("No viable type conversion.");
            }
        } else if (type == String)
        {
            if (a.type == String)
            {
                *((std::string *) container) += *((std::string *) a.container);
            } else
            {
                throw TypeError("No viable type conversion.");
            }
        } else
        {
            throw TypeError("Unsupported operation");
        }
        return *this;
    }


    Object &Object::operator-=(const Object &a)
    {
        if (type == Int)
        {
            if (a.type == Int)
            {
                *((int *) container) -= *((int *) a.container);
            } else if (a.type == Double)
            {
                *this = Object(*((int *) container) - *((double *) a.container));
            } else
            {
                throw TypeError("No viable type conversion.");
            }
        } else if (type == Double)
        {
            if (a.type == Int)
            {
                *((double *) container) -= (double) *((int *) a.container);
            } else if (a.type == Double)
            {
                *((double *) container) -= *((double *) a.container);
            } else
            {
                throw TypeError("No viable type conversion.");
            }
        } else
        {
            throw TypeError("Unsupported operation");
        }
        return *this;
    }

    Object &Object::operator*=(const Object &a)
    {
        if (type == Int)
        {
            if (a.type == Int)
            {
                *((int *) container) *= *((int *) a.container);
            } else if (a.type == Double)
            {
                *this = Object(*((int *) container) * *((double *) a.container));
            } else
            {
                throw TypeError("No viable type conversion.");
            }
        } else if (type == Double)
        {
            if (a.type == Int)
            {
                *((double *) container) *= (double) *((int *) a.container);
            } else if (a.type == Double)
            {
                *((double *) container) *= *((double *) a.container);
            } else
            {
                throw TypeError("No viable type conversion.");
            }
        } else
        {
            throw TypeError("Unsupported operation");
        }
        return *this;
    }

    Object &Object::operator/=(const Object &a)
    {
        if (type == Int)
        {
            if (a.type == Int)
            {
                *((int *) container) /= *((int *) a.container);
            } else if (a.type == Double)
            {
                *this = Object(*((int *) container) / *((double *) a.container));
            } else
            {
                throw TypeError("No viable type conversion.");
            }
        } else if (type == Double)
        {
            if (a.type == Int)
            {
                *((double *) container) /= (double) *((int *) a.container);
            } else if (a.type == Double)
            {
                *((double *) container) /= *((double *) a.container);
            } else
            {
                throw TypeError("No viable type conversion.");
            }
        } else
        {
            throw TypeError("Unsupported operation");
        }
        return *this;
    }

    Object &Object::operator++() {
        if (type != Int)
            throw TypeError("No increment operator fo this type");
        (*(int *) container)++;
        return *this;
    }

    Object &Object::operator--() {
        if (type != Int)
            throw TypeError("No dencrement operator fo this type");
        (*(int *) container)--;
        return *this;
    }

    Object Object::operator++(int) {
        if (type != Int)
            throw TypeError("No increment operator fo this type");
        Object copy = *this;
        (*(int *) container)++;
        return copy;
    }

    Object Object::operator--(int) {
        if (type != Int)
            throw TypeError("No dencrement operator fo this type");
        Object copy = *this;
        (*(int *) container)--;
        return copy;
    }
}