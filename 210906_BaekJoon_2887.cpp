#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define MAX_POINT 100000 + 1
using namespace std;

struct Point {
	int x, y, z, index;
};

struct Edge {
	Point node1, node2;
	int weight;
};

bool cmpX(Point a, Point b) {
	return a.x < b.x;
}

bool cmpY(Point a, Point b) {
	return a.y < b.y;
}

bool cmpZ(Point a, Point b) {
	return a.z < b.z;
}

bool cmp(Edge a, Edge b) {
	return a.weight < b.weight;
}

int getWeight(Edge edge) {
	return min(min(abs(edge.node1.x - edge.node2.x), abs(edge.node1.y - edge.node2.y)),
					abs(edge.node1.z - edge.node2.z));
}

int result = 0, edgeCnt = 0;

int findParent(int x);
void getUnion(Edge edge);
vector<int> parent(MAX_POINT);

int main() {
	int pointNum;
	cin >> pointNum;

	vector<Point> point(pointNum);
	vector<Edge> edge(pointNum);

	for (int i = 0; i < pointNum; i++) {
		cin >> point[i].x >> point[i].y >> point[i].z;
		point[i].index = i;
		parent[i] = i;
	}

	sort(point.begin(), point.end(), cmpX);

	for (int i = 0; i < pointNum - 1; i++) {
		Edge edgeOne;
		edgeOne.node1 = point[i];
		edgeOne.node2 = point[i + 1];
		edgeOne.weight = getWeight(edgeOne);
		edge.push_back(edgeOne);
	}

	sort(point.begin(), point.end(), cmpY);

	for (int i = 0; i < pointNum - 1; i++) {
		Edge edgeOne;
		edgeOne.node1 = point[i];
		edgeOne.node2 = point[i + 1];
		edgeOne.weight = getWeight(edgeOne);
		edge.push_back(edgeOne);
	}

	sort(point.begin(), point.end(), cmpZ);

	for (int i = 0; i < pointNum - 1; i++) {
		Edge edgeOne;
		edgeOne.node1 = point[i];
		edgeOne.node2 = point[i + 1];
		edgeOne.weight = getWeight(edgeOne);
		edge.push_back(edgeOne);
	}

	sort(edge.begin(), edge.end(), cmp);

	for (int i = 0; i < edge.size(); i++) {
		getUnion(edge[i]);

		if (edgeCnt == pointNum) {
			break;
		}
	}

	cout << result;

	return 0;
}

int findParent(int x) {
	if (x == parent[x]) {
		return x;
	}

	return parent[x] = findParent(parent[x]);
}

void getUnion(Edge edge) {
	int node1 = findParent(edge.node1.index);
	int node2 = findParent(edge.node2.index);

	if (node1 != node2) {
		parent[node2] = node1;
		result += edge.weight;
		edgeCnt++;
	}
}