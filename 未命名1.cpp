#include<iostream>
using namespace std;

struct Node {
	Node *l, *r,*par;
	char value;//0,1分别表示未更新，Y，N,子树相等
	Node(Node *par): value(0),par(par),l(0),r(0){}
	~Node()	{
		if (l) delete l;
		if (r) delete r;
	}
};
struct Tree {
	Node *head;
	char line[10] = { 0 };
	void build(char *temp, int n, char c) {
		Node *p = head;
		int i = 0;
		while (i < n) {
			if (temp[i++] == 'H') {
				if (p->l == 0) p->l= new Node(p);
				p = p->l;
			}
			else {
				if (p->r == 0) p->r = new Node(p);
				p = p->r;
			}
		}
		p->value = c;
		update(p);
	}
	void update(Node *p) {
		while (p->par) {
			if (p->par->value == p->value) return;
			if (p->par->value == 0) p->par->value = p->value;
			else p->par->value = 1;
			p = p->par;
		}
	}
	void print(Node *p, int i) {
		if (p == 0) return;
		if (p->value&&p->value != 1) printf("%s%c;",line,p->value);
		else {
			line[i] = 'H';
			print(p->l, i + 1);
			line[i] = 'L';
			print(p->r, i + 1);
			line[i] = '\0';
		}
		
	}
	~Tree() { delete head; }
};

int main(){
	int n, m;
	char temp[10] = { 0 };
	while (scanf("%d %d",&n,&m)!=EOF) {
		if (n == 0 && m == 0) return 0;
		Tree tree;	
		tree.head = new Node(0);
		for (int i = 0; i < n; i++) {
			int none;
			scanf("%d", &none);
			for (int j = 0; j < m; j++) scanf(" %c", &temp[j]);
			char c;
			cin >> c;
			tree.build(temp, m, c);
		}
		tree.print(tree.head,0);
		printf("\n");
	}
}
