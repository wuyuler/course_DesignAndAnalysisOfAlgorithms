#include<iostream>
#include<vector> 
using namespace std;

//从n个数中选取k个数,和为x 
int n, k, x, num[100] = {2,3,4,5};

vector<int> temp;
void output(){
	for(int i=0;i<temp.size();i++)
		cout<<temp[i];
	cout<<endl;
} 
void dfs(int index, int nowK, int sum) {//index当前指向数组元素下标;nowK当前temp中元素个数;sum当前temp中的和 
	if (nowK == k&&sum == x) {
		for (int i = 0; i < k; ++i) {
			printf("结果:%d ", temp[i]);			
		}
		putchar('\n');
		return;
	}
	if (index >= n || nowK >= k || sum > x)	return;
	temp.push_back(num[index]);
	dfs(index + 1, nowK + 1, sum + num[index]);
	output();
	temp.pop_back();//某个k个数组合不符合要求,将最上面的元素出栈 
 	
	dfs(index + 1, nowK, sum);
}


int main(){
	n=4;
	k=2;
	x=9;
	dfs(0,0,0); 
	
}
