// 问题_E_BFS.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<queue>
using namespace std;

int visited[1000][1000];

struct P {
	P* pre;
	int x, y;
	int k;
	P(int x, int y, int k, P *pre) :x(x), y(y), k(k), pre(pre) {}
};
void visit(int x, int y, int k, P *pre, queue<P*> &q) {
	if (visited[x][y])return;
	visited[x][y] = 1;
	P *p = new P(x, y, k, pre);
	q.push(p);
}
bool bfs(int m, int n) {
	for (int i = 0; i <= m; i++) for (int j = 0; j <= n; j++) visited[i][j] = 0;
	if (n % 2 == 1) return 0;
	int src = n / 2;
	queue<P*> q;
	visit(0, 0, 6, 0, q);
	while (!q.empty()) {
		P *p = q.front();
		q.pop();
		int x = p->x, y = p->y;
		if (y == src) {
			return 1;
		}
		visit(m, y, 0, p, q);
		visit(x, n, 1, p, q);
		visit(0, y, 2, p, q);
		visit(x, 0, 3, p, q);
		int min = x < (n - y) ? x : n - y;
		visit(x - min, y + min, 4, p, q);
		min = y < (m - x) ? y : m - x;
		visit(x + min, y - min, 5, p, q);

	}

	return 0;
}
int main()
{
	int m, n;
	while (scanf("%d %d", &m, &n) != EOF) {
		if (m == 0 && n == 0) return 0;
		if (bfs(m, n)) printf("Y\n");
		else printf("N\n");
	}

    return 0;
}

