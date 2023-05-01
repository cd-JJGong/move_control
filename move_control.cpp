#include<stdio.h>

float SetSpd_L, SetSpd_R;
float SetPos_L, SetPos_R;

const int run_target_size = 7;	//总的目标数
float distance[run_target_size] = {1, 1, 1, 1, 1, 90, 1};	//运动距离，这里根据实际情况调，旋转的也是，距离的正负决定了旋转的方向
int direction[run_target_size] = {3, 1, 4, 1, 2, -1, 1};	//用1，2，3，4，-1， -2表示前后左右方向和顺时针、逆时针旋转90°,规定机械臂方向为初始前方
int singlechip = 1;	//单片机，0表示控制前面两个轮子的单片机，1表示后面的单片机

void move_control(int run_target) {
	if (singlechip == 0) {
		switch (direction[run_target])
		{
		case 1:
			SetPos_L = distance[run_target];
			SetPos_R = distance[run_target];
			break;
		case 2:
			SetPos_L = -distance[run_target];
			SetPos_R = -distance[run_target];
			break;
		case 3:
			SetPos_L = -distance[run_target];
			SetPos_R = distance[run_target];
			break;
		case 4:
			SetPos_L = distance[run_target];
			SetPos_R = -distance[run_target];
			break;
		case -1:
			SetPos_L = distance[run_target];
			SetPos_R = -distance[run_target];
			break;
		case -2:
			SetPos_L = -distance[run_target];
			SetPos_R = distance[run_target];
			break;
		default:
			break;
		}
	}
	else {
		switch (direction[run_target])
		{
		case 1:
			SetPos_L = distance[run_target];
			SetPos_R = distance[run_target];
			break;
		case 2:
			SetPos_L = -distance[run_target];
			SetPos_R = -distance[run_target];
			break;
		case 3:
			SetPos_L = distance[run_target];
			SetPos_R = -distance[run_target];
			break;
		case 4:
			SetPos_L = -distance[run_target];
			SetPos_R = distance[run_target];
			break;
		case -1:
			SetPos_L = distance[run_target];
			SetPos_R = -distance[run_target];
			break;
		case -2:
			SetPos_L = -distance[run_target];
			SetPos_R = distance[run_target];
			break;
		default:
			break;
		}
	}
}

int main() {
	int run_target = 0;
	while (run_target < run_target_size) {
		move_control(run_target);
		printf("run_target:%d\n", run_target);
		if (singlechip == 0) {
			printf("左前轮的位置环:%f\n", SetPos_L);
			printf("右前轮的位置环:%f\n", SetPos_R);
		}
		else {
			printf("左后轮的位置环:%f\n", SetPos_L);
			printf("右后轮的位置环:%f\n", SetPos_R);
		}
		run_target++;
	}
	return 0;
}