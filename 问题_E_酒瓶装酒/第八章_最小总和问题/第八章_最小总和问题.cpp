// 第八章_最小总和问题.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
int s = 4;
int map[5][5] = { {0,0,0,0,0}, {0,2,0,0,0},{0,5,4,0,0},{0,1,4,7,0},{0,8,6,8,6} };
int F[5][5] = {0};
int getmin(int m,int n) {
	if (m == s)return map[m][n];
	int left,right;
	if (F[m + 1][n]) {
		left = map[m][n] + F[m + 1][n];
	}
	else {
		left = map[m][n] + getmin(m + 1, n);
	}
	if (F[m + 1][n+1]) {
		right = map[m][n] + F[m + 1][n+1];
	}
	else {
		right = map[m][n] + getmin(m + 1, n+1);
	}
	int min = left > right ? right : left;
	F[m][ n] = min;
	return min;
}
int main()
{	
	cout<<getmin(1, 1);

    return 0;
}

