//¼ÆËãÄæĞòÊı
#include<iostream>
#include<vector>
using namespace std;


int count=0;
int merge(vector<int> v1, vector<int> v2) {
	int num = 0;
	for (int i = 0; i<v1.size(); i++)
		for (int j = 0; j<v2.size(); j++) {
			if (v1[i]>v2[j])
				num++;
		}
	return num;

}
int getNumOfNi(vector<int> v) {
	if (v.size() == 1)return 0;

	vector<int>v1;
	for (int i = 0; i<=v.size() / 2 - 1; i++)
		v1.push_back(v[i]);
	vector<int>v2;
	for (int i = v.size() / 2; i<v.size(); i++)
		v2.push_back(v[i]);
	int num1 = getNumOfNi(v1);
	int num2 = getNumOfNi(v2);

	return num1 + num2 + merge(v1, v2);
}
void output(vector<int> v) {
	for (int i = 0; i<v.size(); i++)
		if (i != v.size() - 1)
			cout << v[i] << endl;
		else cout << v[i];

}



int main(){
//	int n;
//	vector<int> v;
//	vector<int> result;
//	cin>>n;
//	
//	while(n!=0){
//		for(int i=0;i<n;i++){
//			int a;
//			cin>>a;
//			v.push_back(a);
//		}
//		result.push_back(getNumOfNi(v));
//		v.clear();
//		cin>>n;
//	}
//	output(result);
//	return 0;
	
	//²âÊÔ´úÂë
	//int a[5]={2,4,1,3,5};
	
	int a[7]={2, 7 , 1 , 4 , 5 , 3 , 9};
	vector<int> test(a,a+7);
	getni(test);
	cout<<count; 
} 
 
