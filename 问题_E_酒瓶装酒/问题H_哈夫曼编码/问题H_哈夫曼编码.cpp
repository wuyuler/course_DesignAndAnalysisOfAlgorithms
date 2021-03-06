// 问题H_哈夫曼编码.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include<iostream>
using namespace std;

int n;

struct HuffmanNode {
	int weight;
	int lchild, rchild;
	int parent;
	HuffmanNode() {
		lchild = rchild = parent = 0;
	}
};
HuffmanNode *nodes;
int compare(HuffmanNode h1, HuffmanNode h2) {
	return h1.weight < h2.weight;
}
void createTree() {
	//sort(v, v+2*n-1, compare);
	for (int i = n; i < 2 * n - 1; i++) {
		int c = 0, a = 0, b = 0;
		for (int j = 1; j <= i; j++) {//先取两个值
			if (nodes[j].parent == 0 && c < 1) {
				a = j;
				c++;
				continue;
			}
			if (nodes[j].parent == 0) {
				b = j;
				break;
			}

		}
		if (nodes[a].weight < nodes[b].weight) {
			c = a;
			a = b;
			b = c;
		}
		for (int j = 1; j <= i; j++) {//得到权重最小的两个根结点

			if (nodes[j].parent == 0 && j != b && nodes[j].weight < nodes[a].weight)a = j;
			if (nodes[a].weight < nodes[b].weight) {//始终保持a的权重>b的权重
				c = a;
				a = b;
				b = c;
			}
		}
		//两个权重最小的无父结点的结点,得到一个新的无父节点
		nodes[i + 1].weight = nodes[a].weight + nodes[b].weight;
		nodes[i + 1].lchild = b;
		nodes[i + 1].rchild = a;
		nodes[a].parent = i + 1;
		nodes[b].parent = i + 1;
	}
}
int sum=0;
void getAverage(int i,int len) {
	HuffmanNode &node = nodes[i];
	if (node.lchild) {
		getAverage(node.lchild, len+1);
	}
	if (node.rchild) {
		getAverage(node.rchild,len + 1);
	}
	if (node.lchild==0&&node.rchild==0) {
		sum += node.weight*len;
	}
}

int main()
{	
	while (true) {
		cin >> n;
		if (n == 0)break;
		nodes = new HuffmanNode[2 * n + 2];
		
		for (int i = 1; i <= n; i++) {
			char data;
			int weight;
			cin >> data;
			cin >> nodes[i].weight;
		}
		createTree();
		if (n == 1) {
			sum = nodes[1].weight;
		}
		else {
			getAverage(2 * n - 1, 0);
		}
		cout << sum <<endl;
		sum = 0;
	}
	
    return 0;
}

