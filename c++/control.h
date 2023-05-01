#pragma once
#include<iostream>
using namespace std;

class singlechip {	//��Ƭ��
public:
	void setSpd(float L, float R);
	void setPos(float L, float R);
	float setSpd_L, SetSpd_R;	//����ת��
	float setPos_L, setPos_R;	//����λ�û�
};

void singlechip::setSpd(float L, float R) {
	this->setSpd_L = L;
	this->setPos_R = R;
};

void singlechip::setPos(float L, float R) {
	this->setPos_L = L;
	this->setPos_R = R;
}

class move_control {	//�˶�����ϵͳ
public:
	singlechip front;
	singlechip back;
	void setPos(float distance, int direction);
	move_control();
	int run_target_size;	//�˶�����
	float Centimeter_per_ring;	//ÿһ���ľ���
	float* distance;
	int* direction;
};

move_control::move_control() {
	run_target_size = 7;
	distance = new float[run_target_size] {1, 1, 1, 1, 1, 90, 1};	//�˶����룬�������ʵ�����������ת��Ҳ�ǣ������������������ת�ķ���
	direction = new int[run_target_size] {3, 1, 4, 1, 2, -1, 1};	//��1��2��3��4��-1�� -2��ʾǰ�����ҷ����˳ʱ�롢��ʱ����ת90��,�涨��е�۷���Ϊ��ʼǰ��
	this->front.setSpd(1, 1);	//�ٶȻ�Ĭ��1������ʵ�ʵ�
	this->back.setSpd(1, 1);
	this->Centimeter_per_ring = 1;	//ÿһ���ľ���Ĭ��Ϊ1
}

void move_control::setPos(float distance, int direction) {
	distance = distance / this->Centimeter_per_ring;	//���ݾ��뻻�㻷��
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