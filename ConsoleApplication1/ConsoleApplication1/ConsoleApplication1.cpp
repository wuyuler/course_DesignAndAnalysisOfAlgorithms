// ConsoleApplication1.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

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
	int data; //叶子节点为-1,其他按顺序 
	char result;
	struct BinNode *lchild, *rchild;
	BinNode() {
		lchild = NULL;
		rchild = NULL;
	}
	/*~BinNode()
	{
		if (lchild)delete lchild;
		if (rchild)delete rchild;
	}*/
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
bool selectEnd(vector<int> v) {
	int item = 1;
	for (int k = 0; k<v.size(); k++) {
		if (v[k] != -1) {
			item = 0;
			break;
		}
	}
	return item;
}
void deleteEle(vector<int>& v, vector<int> &index) {//标记特定索引的数据为不需要
	vector< int >::iterator k = v.begin();
	for (int i = 0; i<index.size(); i++) {
		v[index[i]] = -1;
	}
}
void getBinTree(vector<BinNode>& vb, vector<Record>& records, int sour, vector<int> term) {//目标树,总数据,症状代号,需要参考的内容 

	if (selectEnd(term)||sour>=M) {
		return;
	}
	else {
		int temp_hasDif = 0;//是否存在,症状相同,诊断结果不同的现象
		//获取症状sour对应所有H,L的结果; 
		vector<char> res_H, res_L;
		vector<int> H_index, L_index; //存储H和L的索引,方便删除 
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
			if (isSame(res_H)) {//如果诊断结果都相同 
				BinNode *b_H= new BinNode;
				b_H->result = res_H[0];
				b_H->data= -1;
				vb[sour].lchild = b_H;//此时该症状可以判断出患病与否 
									   //可以将涉及到的案例都删除掉了
				deleteEle(term, H_index);
			}
			else {//诊断结果有不同,继续下一症状的检查 
				vb[sour].lchild = &vb[sour + 1];
				//getBinTree(vb, records, sour + 1, term);
				temp_hasDif = 1;
			}
		}

		if (res_L.size() > 0) {
			if (isSame(res_L)) {//如果诊断结果都相同 
				BinNode *b_L=new BinNode;
				b_L->result = res_L[0];
				b_L->data = -1;
				vb[sour].rchild = b_L;//此时该症状可以判断出患病与否 
									   //可以将涉及到的案例都删除掉了
				deleteEle(term, L_index);
			}
			else {//诊断结果有不同,继续下一症状的检查 
				vb[sour].rchild = &vb[sour + 1];
				temp_hasDif = 1;
			}
		}
		if(temp_hasDif==1)//仍然存在争议诊断,继续下一个症状的判断
			getBinTree(vb, records, sour + 1, term);
	}



}

void shaveTree(BinNode* b) {
	if (b->lchild == NULL && b->rchild != NULL) {
		b->data = -1;
		b->result = b->rchild->result;
	}
	if (b->lchild != NULL && b->rchild == NULL) {
		b->data = -1;
		b->result = b->lchild->result;
	}
		
}

void output(string s,BinNode& vb) {
	if (vb.data == -1) {
		//cout << s + vb.result+";";
		myresult += s + vb.result + ";";
		
		return;
	}
	string s1 = s;
	if (vb.lchild) {
		//cout << s+"往左";
		output(s + 'H',*vb.lchild);
	}
	if (vb.rchild) {
		//cout << s+"往右";
		output(s+'L', *vb.rchild);
	}

}

void testOutput(BinNode* tree) {
	cout << tree->data<<">";
	if (tree->lchild)testOutput(tree->lchild);
	if (tree->rchild)testOutput(tree->rchild);
}
int main() {
	
	while (true)
	{
		cin >> N >> M;
		if (N!=0&&M!=0) {
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
			//存放所有可能的树节点
			vector<BinNode> vb;
			for (int i = 0; i<M; i++)//0~M-1表示症状 
			{
				BinNode* v_temp = new BinNode;
				v_temp->data = i;
				vb.push_back(*v_temp);
			}

			vector<int> v2;
			for (int i = 1; i <= N; i++)
				v2.push_back(i);//需要记录的item 
			getBinTree(vb, records, 0, v2);
			shaveTree(&vb[0]);
			string s;
			output(s, vb[0]);
			//delete &vb[0];
			lastResult.push_back(myresult);
			myresult = "";
			/*testOutput(&vb[0]);
			cout << endl;*/
		}
		else break;
	}
	for (int i = 0; i < lastResult.size(); i++) {
		if(i!= i < lastResult.size()-1)
			cout << lastResult[i]<<endl;
		else cout << lastResult[i];
	}
	return 0;
}

