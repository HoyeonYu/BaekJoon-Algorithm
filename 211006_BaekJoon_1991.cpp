#include <iostream>
#include <vector>
#define MAX_NODE 26
using namespace std;

struct node {
	char left, right;
};

vector<node> v(MAX_NODE);

void preOrder(char node);
void inOrder(char node);
void postOrder(char node);

int main() {
	int totNum;
	cin >> totNum;

	for (int i = 0; i < totNum; i++) {
		char root, left, right;
		cin >> root >> left >> right;

		v[root - 'A'].left = left;
		v[root - 'A'].right = right;
	}

	preOrder('A');
	cout << "\n";

	inOrder('A');
	cout << "\n";

	postOrder('A');

	return 0;
}

void preOrder(char node) {
	if (node == '.') {
		return;
	}

	cout << node;
	preOrder(v[node - 'A'].left);
	preOrder(v[node - 'A'].right);
}

void inOrder(char node) {
	if (node == '.') {
		return;
	}

	inOrder(v[node - 'A'].left);
	cout << node;
	inOrder(v[node - 'A'].right);
}

void postOrder(char node) {
	if (node == '.') {
		return;
	}

	postOrder(v[node - 'A'].left);
	postOrder(v[node - 'A'].right);
	cout << node;
}