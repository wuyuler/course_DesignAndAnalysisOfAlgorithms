// 问题_E_酒瓶装酒.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
using namespace std;
int M, N;
int flag = 0;
int getRemain(int big, int small,int preRemain) {//本次的大瓶初始就加上上次的小瓶最终剩余
	int remain;//本次的,小瓶最终剩余
	int n = 0;
	while(big - (preRemain + n * small)>=small){
		//为什么是等于,因为取等,最终可能会正好装满,也就是说,remain会取small,这是有可能成功的,但是如果不取等号,最终remain就是0,这是不可能的
		if (n*small+preRemain == N / 2)flag = 1;//n从0开始,即顺便判断了remain本身会不会就是所要求的解
		n++;
	}
	remain = small - (big - (preRemain + n * small));
	return remain;
}
bool hasit(vector<int> v, int a) {
	for (int i = 0; i < v.size(); i++)
		if (v[i] == a)return true;
	return false;
}
vector<int> getALlRemain(int big, int small) {
	vector<int> res;
	int remain = getRemain(big, small,0);
	while (!hasit(res,remain)) {
		res.push_back(remain);
		remain = getRemain(big, small,remain);
	}
	return res;
}
int main()
{
	while (true) {
		cin >> M >> N;
		if (M == 0 && N == 0)
			break;
		if (N % 2 != 0||M==N)
			cout << "N" << endl;
		else {
			if (M < N) {
				getALlRemain(N,M);
			}
			else{
				getALlRemain(M, N);
			}
			if (flag == 1)
				cout << "Y" << endl;
			else
				cout << "N" << endl;
			flag = 0;

		}
	}

}

