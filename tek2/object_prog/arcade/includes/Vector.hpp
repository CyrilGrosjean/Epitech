/*
** EPITECH PROJECT, 2021
** arcade
** File description:
** Vector
*/

#ifndef VECTOR_HPP_
#define VECTOR_HPP_

class Vector2i {
    public:
        Vector2i();
        Vector2i(const Vector2i &);
        Vector2i(int x, int y);
        ~Vector2i();

        Vector2i &operator/(const int div);
        Vector2i &operator=(const Vector2i &vector);
        Vector2i &operator+=(const Vector2i &vector);
        Vector2i &operator*(const int mul);
        bool operator!=(const Vector2i &vector);
        bool operator==(const Vector2i &vector);
        bool operator>(const Vector2i &vector);
        bool operator<(const Vector2i &vector);
        bool operator>=(const Vector2i &vector);
        bool operator<=(const Vector2i &vector);

        int x;
        int y;
};

class Vector3i {
    public:
        Vector3i();
        Vector3i(const Vector3i &);
        Vector3i(int x, int y, int z);
        ~Vector3i();

        Vector3i &operator=(const Vector3i &vector);
        Vector3i &operator+=(const Vector3i &vector);
        Vector3i &operator*(const int mul);
        Vector3i &operator/(const int div);
        bool operator!=(const Vector3i &vector);
        bool operator==(const Vector3i &vector);
        bool operator>(const Vector3i &vector);
        bool operator<(const Vector3i &vector);
        bool operator>=(const Vector3i &vector);
        bool operator<=(const Vector3i &vector);

        int x;
        int y;
        int z;
};

#endif /* !VECTOR_HPP_ */
