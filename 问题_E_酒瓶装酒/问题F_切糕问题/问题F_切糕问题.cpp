// 问题F_切糕问题.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
using namespace std;

int n;//总大小
vector<int> values;
vector<int> F;
int qiege(int i) {//切割大小
	if (i == 0)return 0;
	int maxprice=0;
	int qie = 1;
	int sheng=i;
	while (sheng != 0) {
		int temp;
		sheng = i - qie;
		if (F[sheng] == 0)
			temp = values[qie] + qiege(sheng);
		else
			temp = values[qie] + F[sheng];
		if (maxprice < temp)
			maxprice = temp;
		qie++;
	}
	F[i] = maxprice;
	return maxprice;
}
int main()
{
	while (true) {
		cin >> n;
		if (n == 0)break;
		values.push_back(0);
		F.push_back(0);
		for (int i = 0; i < n; i++) {
			int temp;
			cin >> temp;
			values.push_back(temp);
			F.push_back(0);
		}
		cout << qiege(n)<<endl;
		values.clear();
		F.clear();
	}

    return 0;
}

