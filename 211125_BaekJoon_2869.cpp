#include <iostream>
using namespace std;

int main() { 
	int A, B, V,  day; 
	cin >> A >> B >> V;

	day = (V - B - 1) / (A - B) + 1; 
	cout << day;
	
	return 0; 
}
