// Copyright (C) 2014 Team306

#ifndef BALL_H
#define BALL_H 


#include <QPainter>
#include <QColor>
#include <string>
#include "MyMath.h"

//ballRadius 23.44

enum BALL_STATE { STILL, RUNNING, ON_THE_POCKET };

const float Fslip_GroundToBall = 0.0003f; //滑动摩擦系数
const float Froll_GroundToBall = 0.000022f; //滚动摩擦系数
const float Frotate_GroundToBall=0.000014f; //旋切摩擦系数

const float Fslip_Threshold=(1.0f+1.0f/0.4f)*Fslip_GroundToBall; //滚动摩擦阀值
const float Froll_Threshold=1.0f*Froll_GroundToBall;        //滑动摩擦阀值
const float Frotate_Threshold=1.0f*Frotate_GroundToBall;    //旋切摩擦阀值

const float M=1.0f; //小球质量

class Ball
{
private:
    Vector3 position;  // 重心位置
    Vector3 speed;     //线速度
    Vector3 anglespeed;  //角速度
    float radius;     //半径
    float Im;         //转动惯量

	// ball's info
	std::string name;
	QColor color;

	BALL_STATE ballState;

public:
	Ball();
    Ball(const Vector3& position, float radius);
    Ball(const Vector2& position, float radius);
	~Ball();

    Vector3 getPosition() const;
    void setPosition(const Vector3& v);
    void setPosition(const Vector2& v); //z=0
    Vector3 getSpeed() const;
    void setSpeed(const Vector3& v);
    Vector3 getAngleSpeed() const;
    void setAngleSpeed(const Vector3& v);
	float getRadius() const;
    float getIm() const;
	int getBallState() const;
	void setBallState(int);

	std::string getName() const;
	void setName(std::string);
	void setColor(QColor);

    void ApplyImpulse(const Vector3& impulse,const Vector3& collideposition); //作用冲量
	

    void Move();
	virtual void Draw(QPainter &);

};


#endif
