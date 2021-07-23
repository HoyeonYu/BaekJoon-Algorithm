#include <iostream>
#include <vector>
#include <algorithm>
#define p pair<int, string>
using namespace std;

bool cmp(p a, p b) {
	return a.first < b.first;
};

int main() {
	int num;
	cin >> num;
	vector<p> vec;

	for (int i = 0; i < num; i++) {
		int age;
		string name;
		cin >> age >> name;
		vec.push_back({ age, name });
	}

	stable_sort(vec.begin(), vec.end(), cmp);

	for (int i = 0; i < num; i++) {
		cout << vec[i].first << " " << vec[i].second << "\n";
	}

	return 0;
}