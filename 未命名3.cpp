#include <iostream>
using namespace std;
int n;
int m;
int x;//ȥ������ı�� 
struct sort {
	char t[1002][12];
	int size;
};
void SolutionTree(sort s, int k)
{//s���ü�¼,kҪ�жϵ�֢״ 
	sort b;
	sort c;
	b.size = 1;
	c.size = 1;
	bool end = true;
	if (s.size == 0)
		return; 
	for (int i = 1; i < s.size; i++)
	{
		if (s.t[i][m + 1] != s.t[i + 1][m + 1])
		{//�Ƿ񻼲��������� 
			end = false;
			break;
		}
	}
	if (end == true)
	{//k��ǰ��֢״�Ѿ����Խ������ 
		for (int i = 1; i < k; i++)
			cout << s.t[1][i];
		cout << s.t[1][m + 1] <<";";
		return;
	}
	for (int i = 1; i <= s.size; i++)
	{//����ǰ֢״��H��L�ļ�¼�ֿ�,�ݹ��ȥ��һ��֢״�ж� 
		if (s.t[i][k] == 'H')
		{
			for (int j = 1; j<= m+1; j++)
			{
				b.t[b.size][j] = s.t[i][j];
			}
			b.size++;
		}
		else {
			for (int j = 1; j <= m+1; j++)
			{
				c.t[c.size][j] = s.t[i][j];
			}
			c.size++;
		}
	}
	b.size--;
	c.size--;
	SolutionTree(b, k + 1);
	SolutionTree(c, k + 1);
}
int main()
{
	sort a;
	while (1)
	{
		cin >> n >> m;
		if (n == 0 && m == 0)
			break;
		for (int i = 1; i <= n; i++)
		{
			cin >> x;
			for (int j = 1; j <= m+1; j++)
			{
			    cin>>a.t[i][j];
			}
		}
		a.size = n;
		SolutionTree(a, 1);
		cout << endl;
	}
}

