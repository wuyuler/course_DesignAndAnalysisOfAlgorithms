// 问题G_开餐馆.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;

int n;
int	k;
int m[1001];
int p[1001];
int F[1001];
int getmax(int i) {
	if (F[i] != 0)return F[i];
	if (i == 0)return 0;
	if (i == 1)
	{	
		F[i] = p[i];
		return p[i];
	}
	int maxmoney=0;
	//不在当前位置创建
	maxmoney = getmax(i - 1);
	int left=1;
	int flag = 0;
	while (m[i - left] + k > m[i]) {
		left++;
		if (i - left == 0) {
			flag = 1;
			break;
		}
	}
	if (flag == 0) {
		int temp;
		/*if (F[i - left] == 0)
			temp = p[i] + getmax(i - left);
		else
			temp = p[i] + F[i - left];*/
		temp= p[i] + getmax(i - left);
		if (temp > maxmoney)
			maxmoney = temp;
	}
	else {
		if (p[i] > maxmoney)
			maxmoney = p[i];
	}
	F[i] = maxmoney;
	return maxmoney;
}
int main()
{
	while (true) {
		cin >> n;
		if (n == 0)break;
		m[0] = 0;
		p[0] = 0;
		F[0] = 0;
		for (int i = 1; i <= n; i++) {
			cin >> m[i];
			F[i] = 0;
		}
			
		for (int i = 1; i <= n; i++)
			cin >> p[i];
		cin >> k;
		cout << getmax(n)<<endl;
	}
    return 0;
}

