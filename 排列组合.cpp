#include<iostream>
#include<vector> 
using namespace std;

//��n������ѡȡk����,��Ϊx 
int n, k, x, num[100] = {2,3,4,5};

vector<int> temp;
void output(){
	for(int i=0;i<temp.size();i++)
		cout<<temp[i];
	cout<<endl;
} 
void dfs(int index, int nowK, int sum) {//index��ǰָ������Ԫ���±�;nowK��ǰtemp��Ԫ�ظ���;sum��ǰtemp�еĺ� 
	if (nowK == k&&sum == x) {
		for (int i = 0; i < k; ++i) {
			printf("���:%d ", temp[i]);			
		}
		putchar('\n');
		return;
	}
	if (index >= n || nowK >= k || sum > x)	return;
	temp.push_back(num[index]);
	dfs(index + 1, nowK + 1, sum + num[index]);
	output();
	temp.pop_back();//ĳ��k������ϲ�����Ҫ��,���������Ԫ�س�ջ 
 	
	dfs(index + 1, nowK, sum);
}


int main(){
	n=4;
	k=2;
	x=9;
	dfs(0,0,0); 
	
}
