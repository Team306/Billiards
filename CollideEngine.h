#ifndef COLLIDEENGINE_H
#define COLLIDEENGINE_H

#include "MyMath.h"
#include "Ball.h"

struct Collision
{
    Vector3 CollidePosition; //撞击点分离
    Vector3 Vr;   //撞前相对速度
    Vector3 _N;  //碰撞垂直方向
    Vector3 _T;  //碰撞法线方向
    Vector3  Ra;  //重心到撞击点向量(小球a)
    Vector3  Va; //撞击点的速度(小球a)
    Vector3  Rb;  //重心到撞击点向量(刚体b)
    Vector3  Vb; //撞击点的速度(刚体b)
    float Vn; //法线方向相对速度大小
    float Vt;  //摩擦力方向速度大小

    Vector3 In; //正冲量
    Vector3 It;  //摩擦冲量
    //计算中用到的常量因子
    float  Ca;
    float  Cb;

};

const float E_BallToBall = 0.9f; //球与球之间的碰撞恢复系数
const float E_WallToBall = 0.7f; //球与墙之间的碰撞恢复系数
const float F_BallToBall = 0.1f; //球与球之间的摩擦系数
const float F_WallToBall = 0.5f; //球与墙之间的摩擦系数

class CollideEngine
{
public:
    CollideEngine();
    ~CollideEngine();
    bool DectBallToBallCollision(const Ball& ballA,const Ball& ballB);
    void ProcessBallToBallCollision(Ball& ballA,Ball& ballB);
};

#endif // COLLIDEENGINE_H
