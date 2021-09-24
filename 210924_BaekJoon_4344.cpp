#include <iostream>
#include <vector>
using namespace std;

int main() {
	int totNum;
	cin >> totNum;

	for (int i = 0; i < totNum; i++) {
		float sum = 0;
		int inNum;
		cin >> inNum;
		vector<int> vec;

		for (int j = 0; j < inNum; j++) {
			int num;
			cin >> num;
			vec.push_back(num);
			sum += num;
		}

		int higher = 0;
		double avg = sum / inNum;

		for (int j = 0; j < inNum; j++) {
			if (vec[j] > avg) {
				higher++;
			}
		}

		float ans = (higher / (float)inNum) * 100;
		printf("%.3f%%\n", ans);
	}
		 
	return 0;
}