#include <iostream>
#include <vector>
#include<string>
using namespace std;
struct Record {
	int number;
	vector <char> v;
};
struct Node {
	char data;
	Node *lchild, *rchild;
	Node(char ch) {
		data = ch;
		lchild = NULL;
		rchild = NULL;
	}
};
Node* Bintree(vector<char> c,int index,int n)
{
	char ch = c[index];
	if (n == c.size()) return NULL;
	Node *node = new Node(ch);
	if (c[n] == 'H')
		node->lchild = Bintree(c, index, n + 1);
	if (c[n] == 'L')
		node->rchild = Bintree(c, index, n + 1);
	return node;
}

Node* mergeTrees(Node* t1, Node* t2) {
	if (t1 && t2) {
		Node *root = new Node('0');
		if (t1->data != NULL)
			root->data = t1->data;
		else
			root->data = t2->data;
		root->lchild = mergeTrees(t1->lchild, t2->lchild);
		root->rchild = mergeTrees(t1->rchild, t2->rchild);
		return root;
	}
	else {
		return t1 ? t1 : t2;
	}
}

void deletePlot(Node *node)
{
	if (node->rchild == NULL || node->lchild == NULL)
	{
		node->rchild = NULL;
		node->lchild = NULL;
	}
	if (node->rchild)
		deletePlot(node->rchild);
	if (node->lchild)
		deletePlot(node->lchild);
}
void output(string s, Node *node)
{
	if (node->lchild == NULL&&node->rchild == NULL)
	{
		cout << s<< node->data << ";";
	}
	if (node->lchild)
	{
		output(s+'H', node->lchild);
	}
	if (node->rchild)
	{
		output(s+'L', node->rchild);
	}
}
int main()
{
	int m,n;
	while (1)
	{
		vector<Record> users;
		cin >> m;
		cin >> n;
		if (m == 0 && n == 0)
			break;
		for (int i = 1; i <= m; i++)
		{
			Record r;
			int a;
			cin >> a;
			r.number = a;
			for (int j = 0; j <= n; j++)
			{
				char d;
				cin >> d;
				r.v.push_back(d);
			}
			users.push_back(r);
		}
		Node *node = Bintree(users[0].v, n, 0);
		for (int i = 1; i < n; i++)
		{
			Node *node1= Bintree(users[i].v, n, 0);
			node = mergeTrees(node, node1);
		}
		deletePlot(node);
		output("",node);
		cout << endl;
	}
}
