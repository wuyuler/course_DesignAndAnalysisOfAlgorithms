// 第八章_矩阵连乘问题.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
using namespace std;

struct Mat {
	int m;
	int n;
	Mat(int m,int n):m(m),n(n){}
};

Mat src[3] = { Mat(1,1000),Mat(1000,1),Mat(1,1000) };
int n = 3;

Mat getmin(int a,int b) {//从Aa到Ab


}

int main()
{
    return 0;
}

