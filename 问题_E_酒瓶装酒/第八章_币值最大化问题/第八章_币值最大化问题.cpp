// 第八章_币值最大化问题.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
int F[100];
int n;
int C[100];//币值
int CoinRow(int i) {
	if (i == 0)return 0;
	if (i == 1) {
		F[i] = C[i];
		return F[i];
	}
	int max = CoinRow(i - 1);//不包含最后一枚
	//包含最后一枚
	int temp;
	if (F[i-2] == 0)
		temp = C[i] + CoinRow(i - 2);
	else
		temp = C[i] + F[i - 2];
	if (temp > max)
		max = temp;
	F[i] = max;
	return max;
}

void CoinRow2() {
	F[0] = 0;
	F[1] = C[1];
	for (int i = 2; i <= n; i++) {
		int max = F[i - 1];
		int temp = C[i] + F[i - 2];
		F[i] = max > temp ? max : temp;
	}
}
int main()
{	
	while (true) {
		cin >> n;
		if (n == 0)break;
		F[0] = 0;
		C[0] = 0;
		for (int i = 1; i <= n; i++) {
			cin >> C[i];
			F[i] = 0;
		}
		CoinRow2();
		cout << F[n] << endl;
	}
	return 0;
}

