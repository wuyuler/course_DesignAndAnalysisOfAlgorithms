// ����_E_��ƿװ��.cpp: �������̨Ӧ�ó������ڵ㡣
//

#include<iostream>
#include<vector>
using namespace std;

int M, N;


int getRemain(int big, int small,int preRemain) {//���εĴ�ƿ��ʼ�ͼ����ϴε�Сƿ����ʣ��
	int remain;//���ε�,Сƿ����ʣ��
	int n = 0;
	while(big - (preRemain + n * small)>=small){
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
				int x = M, y = N;
				int n = 0;
				int flag = 0;
				while (y - n * x >= 0) {
					if (y - n * x == N / 2)flag = 1;
					n++;
				}
				vector<int> v = getALlRemain(N, M);
				for (int i = 0; i < v.size(); i++) {
					if (v[i] == N / 2)flag = 1;
				}
				if (flag == 1)
					cout << "Y" << endl;
				else
					cout << "N" << endl;
			}
			else{
				//m>n
				int flag = 0;
				vector<int> v = getALlRemain(M, N);
				for (int i = 0; i < v.size(); i++) {
					if (v[i] == N / 2)flag = 1;
				}
				if (flag == 1)
					cout << "Y" << endl;
				else
					cout << "N";
			}

		}
//		vector<int> v= getALlRemain(8, 5);
//		for (int i = 0; i < v.size(); i++)
//			cout << v[i]<<endl;

	}
    return 0;
}


