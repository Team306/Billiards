#ifndef MYMATH_H
#define MYMATH_H

#include <iostream>
#include <math.h>
#include "assert.h"
using namespace std;

class Vector2
{
private:
    float x;
    float y;

public:
    Vector2(float x = 0.0f, float y = 0.0f);
    ~Vector2();

    // get and set methods
    float getX() const;
    float getY() const;
    void setXY(float, float);

    // override operators
    Vector2 operator+(Vector2 &) const;
    Vector2 operator-(Vector2 &) const;
    Vector2 operator*(float) const;
    float dotProduct(Vector2 &) const;
    // Vector2 crossProduct(Vector2 &);

    Vector2 operator+=(Vector2 &);
    Vector2 operator-=(Vector2 &);

    float Length() const; // length
    float distanceBetween(Vector2 &) const;

    Vector2 getNormalize() const;
    Vector2 getVertical() const;
};



class Vector3
{
private:
    float x,y,z;
public:
    Vector3(float x=0.0f,float y=0.0f,float z=0.0f);
    Vector3(const Vector2& v);
    ~Vector3();
    float operator[](int i) const;
    float setX(float x);
    float setY(float y);
    float setZ(float z);

    //兼容2维向量
    float getX() const;
    float getY() const;
    void setXY(float, float);

    Vector3 operator+(const Vector3& v) const;
    Vector3 operator-(const Vector3& v) const;
    Vector3& operator+=(const Vector3& v);
    Vector3& operator-=(const Vector3& v);
    Vector3 operator*(float f) const; //数乘
    Vector3 operator/(float f) const; //数除
    Vector3& operator*=(float f);
    Vector3& operator/=(float f);
    Vector3& operator-();

    float Length2() const;  //向量模平方
    float Length() const;   //向量模
    void Normalize(); //归一化为单位向量
    float DistanceTo(const Vector3& v) const;//两点距离
};
float DotProduct(const Vector3& v1,const Vector3& v2); //点积
Vector3 CrossProduct(const Vector3& v1,const Vector3& v2); //叉乘
float DistanceBetween(const Vector3& v1,const Vector3& v2);
Vector3 GetNormalize(const Vector3& v);


#endif // MYMATH_H
