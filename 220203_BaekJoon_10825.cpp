#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Student {
	string name;
	int score1, score2, score3;
};

bool cmp(Student stud1, Student stud2) {
	if (stud1.score1 != stud2.score1) {
		return stud1.score1 > stud2.score1;
	}

	if (stud1.score2 != stud2.score2) {
		return stud1.score2 < stud2.score2;
	}

	if (stud1.score3 != stud2.score3) {
		return stud1.score3 > stud2.score3;
	}

	return stud1.name < stud2.name;
}

int main() {
	int inputNum;
	cin >> inputNum;

	vector<Student> studVec;

	for (int i = 0; i < inputNum; i++) {
		Student stud;
		string name;
		int score1, score2, score3;
		cin >> stud.name >> stud.score1 >> stud.score2 >> stud.score3;
		
		studVec.push_back(stud);
	}

	sort(studVec.begin(), studVec.end(), cmp);

	for (int i = 0; i < inputNum; i++) {
		cout << studVec[i].name << "\n";
	}

	return 0;
}