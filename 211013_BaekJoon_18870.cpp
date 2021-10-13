#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_POINTS 1000000 + 1
using namespace std;

int main() {
	int num;
	cin >> num;

	vector<int> points, idx;

	for (int i = 0; i < num; i++) {
		int point;
		cin >> point;

		points.push_back(point);
		idx.push_back(point);
	}
	
	sort(idx.begin(), idx.end());
	idx.erase(unique(idx.begin(), idx.end()), idx.end());

	for (int i = 0; i < points.size(); i++) {
		cout << lower_bound(idx.begin(), idx.end(), points[i]) - idx.begin() << " ";
	}

	return 0;
}