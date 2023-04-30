#pragma once
#include<iostream>
using namespace std;

class singlechip {	//单片机
public:
	void setSpd(float L, float R);
	void setPos(float L, float R);
	float setSpd_L, SetSpd_R;	//左右转速
	float setPos_L, setPos_R;	//左右位置环
};

void singlechip::setSpd(float L, float R) {
	this->setSpd_L = L;
	this->setPos_R = R;
};

void singlechip::setPos(float L, float R) {
	this->setPos_L = L;
	this->setPos_R = R;
}

class move_control {	//运动控制系统
public:
	singlechip front;
	singlechip back;
	void setPos(float distance, int direction);
	move_control();
	int run_target_size;	//运动段数
	float Centimeter_per_ring;	//每一环的距离
	float* distance;
	int* direction;
};

move_control::move_control() {
	run_target_size = 7;
	distance = new float[run_target_size] {1, 1, 1, 1, 1, 90, 1};	//运动距离，这里根据实际情况调，旋转的也是，距离的正负决定了旋转的方向
	direction = new int[run_target_size] {3, 1, 4, 1, 2, -1, 1};	//用1，2，3，4，-1， -2表示前后左右方向和顺时针、逆时针旋转90°,规定机械臂方向为初始前方
	this->front.setSpd(1, 1);	//速度环默认1，根据实际调
	this->back.setSpd(1, 1);
	this->Centimeter_per_ring = 1;	//每一环的距离默认为1
}

void move_control::setPos(float distance, int direction) {
	distance = distance / this->Centimeter_per_ring;	//根据距离换算环数
	switch (direction)
	{
	case 1:
		this->front.setPos(distance, distance);
		this->back.setPos(distance, distance);
		break;
	case 2:
		this->front.setPos(-distance, -distance);
		this->back.setPos(-distance, -distance);
		break;
	case 3:
		this->front.setPos(-distance, distance);
		this->back.setPos(distance, -distance);
		break;
	case 4:
		this->front.setPos(distance, -distance);
		this->back.setPos(-distance, distance);
		break;
	case -1:
		this->front.setPos(distance, -distance);
		this->back.setPos(distance, -distance);
		break;
	case -2:
		this->front.setPos(-distance, distance);
		this->back.setPos(-distance, distance);
		break;
	default:
		break;
	}
}