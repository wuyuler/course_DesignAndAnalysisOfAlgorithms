#include<iostream>
#include<string>
#include<vector>
using namespace std;

int N, M;
vector<string> lastResult;
string myresult;
struct Record {
	int item;
	char result;
	vector<char> v;
	Record(int item, char result, vector<char> v) :item(item), result(result), v(v) {
	}
};

struct BinNode {
	int data; //Ҷ�ӽڵ�Ϊ-1,������˳�� 
	char result;
	BinNode *lchild, *rchild;
	BinNode() {
		lchild = NULL;
		rchild = NULL;
	}
	~BinNode(){
		if(lchild)delete lchild;
		if(rchild)delete rchild;
	} 
};


bool isSame(vector<char> v) {
	char c = v[0];
	int item = 1;
	for (int k = 0; k<v.size(); k++) {
		if (v[k] != c) {
			item = 0;
			break;
		}
	}
	return item;
}

void deleteEle(vector<int>& v, vector<int> &index) {//ɾ���ض�����������
	vector< int >::iterator k = v.begin();
	for (int i = 0; i<index.size(); i++) {
		v[index[i]] = -1;
	}
}
void getBinTree(vector<BinNode>& vb, vector<Record>& records, int sour, vector<int> term) {//Ŀ����,������,֢״����,��Ҫ�ο������� 

	if (term.size()<=0||sour>=M) {
		return;
	}
	else {
		int temp_hasDif = 0;//�Ƿ����,֢״��ͬ,��Ͻ����ͬ������
		//��ȡ֢״sour��Ӧ����H,L�Ľ��; 
		vector<char> res_H, res_L;
		vector<int> H_index, L_index; //�洢H��L������,����ɾ�� 
		for (int i = 0; i<term.size(); i++) {
			if (term[i] != -1) {
				Record r = records[term[i] - 1];
				if (r.v[sour] == 'H') {
					res_H.push_back(r.result);
					H_index.push_back(i);
				}
				else {
					res_L.push_back(r.result);
					L_index.push_back(i);
				}
			}
		}

		if (res_H.size() > 0) {
			if (isSame(res_H)) {//�����Ͻ������ͬ 
				BinNode *b_H= new BinNode;
				b_H->result = res_H[0];
				b_H->data= -1;
				vb[sour].lchild = b_H;//��ʱ��֢״�����жϳ�������� 
			   //���Խ��漰���İ�����ɾ������
				deleteEle(term, H_index);
			}
			else {//��Ͻ���в�ͬ,������һ֢״�ļ�� 
				vb[sour].lchild = &vb[sour + 1];
				//getBinTree(vb, records, sour + 1, term);
				temp_hasDif = 1;
			}
		}

		if (res_L.size() > 0) {
			if (isSame(res_L)) {//�����Ͻ������ͬ 
				BinNode *b_L=new BinNode;
				b_L->result = res_L[0];
				b_L->data = -1;
				vb[sour].rchild = b_L;//��ʱ��֢״�����жϳ�������� 
									   //���Խ��漰���İ�����ɾ������
				deleteEle(term, L_index);
			}
			else {//��Ͻ���в�ͬ,������һ֢״�ļ�� 
				vb[sour].rchild = &vb[sour + 1];
				//getBinTree(vb, records, sour + 1, term);
				temp_hasDif = 1;
			}
		}
		if(temp_hasDif==1)
			getBinTree(vb, records, sour + 1, term);
	}
}

void output(string s,BinNode& vb) {
	if (vb.data == -1) {
		//cout << s + vb.result+";";
		myresult += s + vb.result + ";";
		return;
	}

	if (vb.lchild) {
		//cout << s+"����";
		output(s + 'H',*vb.lchild);
	}
	if (vb.rchild) {
		//cout << s+"����";
		output(s + 'L', *vb.rchild);
	}

}
int main() {
	
	while (true)
	{
		cin >> N >> M;
		if (N*M) {
			vector<Record> records;
			for (int i = 0; i<N; i++) {
				int item;
				cin >> item;
				vector<char> v;
				for (int j = 0; j<M; j++) {
					char c;
					cin >> c;
					v.push_back(c);
				}
				char res;
				cin >> res;
				records.push_back(Record(item, res, v));
			}
			vector<BinNode> vb;
			for (int i = 0; i<M; i++)//0~M-1��ʾ֢״ 
			{
				BinNode* v_temp = new BinNode;
				v_temp->data = i;
				vb.push_back(*v_temp);
			}

			vector<int> v2;
			for (int i = 1; i <= N; i++)
				v2.push_back(i);//��Ҫ��¼��item 
			getBinTree(vb, records, 0, v2);
			string s;
			output(s, vb[0]);
			lastResult.push_back(myresult);
			myresult = "";
		}
		else break;
	}
	for (int i = 0; i < lastResult.size(); i++) {
		if(i!= lastResult.size()-1)
			cout << lastResult[i]<<endl;
		else cout << lastResult[i];
	}
	return 0;
}
