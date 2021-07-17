#include <iostream>
#include <map>
using namespace std;

long long N, P, Q;
map<long long, long long> questMap;

long long getNum(long long idx);

int main() {
	cin >> N >> P >> Q;
	questMap.insert({ 0, 1 });
	cout << getNum(N);

	return 0;
}

long long getNum(long long idx) {
	if (questMap.find(idx) != questMap.end()) {
		return questMap.find(idx)->second;
	}

	questMap.insert({ idx, getNum(idx / P) + getNum(idx / Q) });

	return questMap.find(idx)->second;
}