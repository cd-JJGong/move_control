#include<iostream>
#include "control.h"

int main() {
	move_control machine;
	int run_target = 1;
	while (run_target <= machine.run_target_size) {
		machine.setPos(machine.distance[run_target-1], machine.direction[run_target-1]);	//����������λ�û�
		cout << "run_target:" << run_target << endl;
		cout << "��ǰ�ֵ�λ�û�:" << machine.front.setPos_L << endl;
		cout << "��ǰ�ֵ�λ�û�:" << machine.front.setPos_R << endl;
		cout << "����ֵ�λ�û�:" << machine.back.setPos_L << endl;
		cout << "�Һ��ֵ�λ�û�:" << machine.back.setPos_R << endl;
		cout << endl;
		run_target++;
	}
	return 0;
}