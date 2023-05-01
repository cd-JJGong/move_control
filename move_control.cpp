#include<stdio.h>

float SetSpd_L, SetSpd_R;
float SetPos_L, SetPos_R;

const int run_target_size = 7;	//�ܵ�Ŀ����
float distance[run_target_size] = {1, 1, 1, 1, 1, 90, 1};	//�˶����룬�������ʵ�����������ת��Ҳ�ǣ������������������ת�ķ���
int direction[run_target_size] = {3, 1, 4, 1, 2, -1, 1};	//��1��2��3��4��-1�� -2��ʾǰ�����ҷ����˳ʱ�롢��ʱ����ת90��,�涨��е�۷���Ϊ��ʼǰ��
int singlechip = 1;	//��Ƭ����0��ʾ����ǰ���������ӵĵ�Ƭ����1��ʾ����ĵ�Ƭ��

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
			printf("��ǰ�ֵ�λ�û�:%f\n", SetPos_L);
			printf("��ǰ�ֵ�λ�û�:%f\n", SetPos_R);
		}
		else {
			printf("����ֵ�λ�û�:%f\n", SetPos_L);
			printf("�Һ��ֵ�λ�û�:%f\n", SetPos_R);
		}
		run_target++;
	}
	return 0;
}