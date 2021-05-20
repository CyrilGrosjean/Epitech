/*
** EPITECH PROJECT, 2021
** arcade
** File description:
** Vector
*/

#include "../includes/Vector.hpp"

Vector2i::Vector2i()
{
    this->x = 0;
    this->y = 0;
}

Vector2i::Vector2i(const Vector2i &vect)
{
    this->x = vect.x;
    this->y = vect.y;
}

Vector2i::Vector2i(int x, int y)
{
    this->x = x;
    this->y = y;
}

Vector2i &Vector2i::operator=(const Vector2i &vector)
{
    this->x = vector.x;
    this->y = vector.y;
    return *this;
}

Vector2i &Vector2i::operator+=(const Vector2i &vector)
{
    this->x += vector.x;
    this->y += vector.y;
    return *this;
}

Vector2i &Vector2i::operator*(const int mul)
{
    this->x *= mul;
    this->y *= mul;
    return *this;
}

Vector2i &Vector2i::operator/(const int div)
{
    this->x /= div;
    this->y /= div;
    return *this;
}

bool Vector2i::operator!=(const Vector2i &vector)
{
    return (this->x != vector.x || this->y != vector.y);
}

bool Vector2i::operator==(const Vector2i &vector)
{
    return (this->x == vector.x && this->y == vector.y);
}

bool Vector2i::operator>(const Vector2i &vector)
{
    return (this->x > vector.x && this->y > vector.y);
}

bool Vector2i::operator<(const Vector2i &vector)
{
    return (this->x < vector.x && this->y < vector.y);
}

bool Vector2i::operator>=(const Vector2i &vector)
{
    return (this->x >= vector.x && this->y >= vector.y);
}

bool Vector2i::operator<=(const Vector2i &vector)
{
    return (this->x <= vector.x && this->y <= vector.y);
}

Vector2i::~Vector2i()
{
}

Vector3i::Vector3i()
{
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

Vector3i::Vector3i(const Vector3i &vector)
{
    this->x = vector.x;
    this->y = vector.y;
    this->z = vector.z;
}

Vector3i::Vector3i(int x, int y, int z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

Vector3i &Vector3i::operator=(const Vector3i &vector)
{
    this->x = vector.x;
    this->y = vector.y;
    this->z = vector.z;
    return *this;
}

Vector3i &Vector3i::operator+=(const Vector3i &vector)
{
    this->x += vector.x;
    this->y += vector.y;
    this->z += vector.z;
    return *this;
}

Vector3i &Vector3i::operator*(const int mul)
{
    this->x *= mul;
    this->y *= mul;
    this->z *= mul;
    return *this;
}

Vector3i &Vector3i::operator/(const int div)
{
    this->x /= div;
    this->y /= div;
    this->z /= div;
    return *this;
}

bool Vector3i::operator!=(const Vector3i &vector)
{
    return (this->x != vector.x || this->y != vector.y || this->z != vector.z);
}

bool Vector3i::operator==(const Vector3i &vector)
{
    return (this->x == vector.x && this->y == vector.y && this->z == vector.z);
}

bool Vector3i::operator>(const Vector3i &vector)
{
    return (this->x > vector.x && this->y > vector.y && this->z > vector.z);
}

bool Vector3i::operator<(const Vector3i &vector)
{
    return (this->x < vector.x && this->y < vector.y && this->z < vector.z);
}

bool Vector3i::operator>=(const Vector3i &vector)
{
    return (this->x >= vector.x && this->y >= vector.y && this->z >= vector.z);
}

bool Vector3i::operator<=(const Vector3i &vector)
{
    return (this->x <= vector.x && this->y <= vector.y && this->z <= vector.z);
}

Vector3i::~Vector3i()
{
}
