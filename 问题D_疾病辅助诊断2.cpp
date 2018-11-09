#include<iostream>
#include<string>
#include<vector>
using namespace std;
int N;
int M;
int x;//去掉多余的编号 
struct sort {
	char t[1002][12];
	int size;
};


void DecTree(sort s,int k){//s表示可用记录,k表示当前症状
	
	int end=1; 
	//终止条件
	
	if(s.size==0)return;
	for(int i=1;i<s.size;i++){
		//诊断是否有冲突
		if(s.t[i][M+1]!=s.t[i+1][M+1]) {
			end=0;
			break;
		}
	} 
	if(end==1){//出现可行判断,进行打印 
		for(int i=1;i<k;i++){//将当前症状前的症状打印 
			cout<<s.t[1][i];
		}
		cout<<s.t[1][M+1]<<";"; 
		return;
	}else{
		sort H;
		sort L;
		H.size=0;
		L.size=0;
		//否则将当前症状按高低分为两组
		for(int i=1;i<=s.size;i++){
			if(s.t[i][k]=='H'){
				for(int j=1;j<=M+1;j++)
					H.t[H.size+1][j]=s.t[i][j];
				H.size++;	
				
					
			}else{
				for(int j=1;j<=M+1;j++)
					L.t[L.size+1][j]=s.t[i][j];
				L.size++;
			}
			
		} 
		DecTree(H,k+1);
		DecTree(L,k+1);
	}
}
int main() {
	sort a;
	while (1)
	{
		cin >> N >> M;
		if (N == 0 && M == 0)
			break;
		for (int i = 1; i <= N; i++)
		{
			cin >> x;
			for (int j = 1; j <= M+1; j++)
			{
			    cin>>a.t[i][j];
			}
		}
		a.size = N;
		DecTree(a, 1);
		cout << endl;
	}
	return 0;
}
