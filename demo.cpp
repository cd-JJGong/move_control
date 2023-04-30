#include<iostream>
#include "control.h"

int main() {
	move_control machine;
	int run_target = 1;
	while (run_target <= machine.run_target_size) {
		machine.setPos(machine.distance[run_target-1], machine.direction[run_target-1]);	//这行是设置位置环
		cout << "run_target:" << run_target << endl;
		cout << "左前轮的位置环:" << machine.front.setPos_L << endl;
		cout << "右前轮的位置环:" << machine.front.setPos_R << endl;
		cout << "左后轮的位置环:" << machine.back.setPos_L << endl;
		cout << "右后轮的位置环:" << machine.back.setPos_R << endl;
		cout << endl;
		run_target++;
	}
	return 0;
}