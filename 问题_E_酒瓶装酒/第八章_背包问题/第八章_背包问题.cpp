// 第八章_背包问题.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
using namespace std;
int n = 5;
int weight[6] = {0,3,2,1,4,5};
int value[6] = {0,25,20,15,40,50};
int W = 6;
int F[100][100];
vector<int> best;
void getmax() {
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= W; j++) {
			if (j - weight[i] < 0)
				F[i][j] = F[i - 1][j];
			else {
				int max = F[i - 1][j];
				int temp =value[i]+ F[i - 1][j - weight[i]];
				F[i][j] = max > temp ? max : temp;
			}
		}
	cout << F[n][W];
}
void getbest() {
	int i = n, j = W;
	while (i != 0 && F[i][j] != 0) {
		if (F[i][j] == F[i - 1][j])
			i--;
		else {
			best.push_back(i);
			j = j - weight[i];
			i--;
		}
	}
}


int main()
{	
	getmax();
	getbest();
	for (int i = 0; i < best.size(); i++)
		cout << best[i];
    return 0;
}

