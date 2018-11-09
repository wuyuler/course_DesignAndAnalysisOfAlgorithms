#include<iostream>
#include<string>
#include<vector>
using namespace std;
int N;
int M;
int x;//ȥ������ı�� 
struct sort {
	char t[1002][12];
	int size;
};


void DecTree(sort s,int k){//s��ʾ���ü�¼,k��ʾ��ǰ֢״
	
	int end=1; 
	//��ֹ����
	
	if(s.size==0)return;
	for(int i=1;i<s.size;i++){
		//����Ƿ��г�ͻ
		if(s.t[i][M+1]!=s.t[i+1][M+1]) {
			end=0;
			break;
		}
	} 
	if(end==1){//���ֿ����ж�,���д�ӡ 
		for(int i=1;i<k;i++){//����ǰ֢״ǰ��֢״��ӡ 
			cout<<s.t[1][i];
		}
		cout<<s.t[1][M+1]<<";"; 
		return;
	}else{
		sort H;
		sort L;
		H.size=0;
		L.size=0;
		//���򽫵�ǰ֢״���ߵͷ�Ϊ����
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
