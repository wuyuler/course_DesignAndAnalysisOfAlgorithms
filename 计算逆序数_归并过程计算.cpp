#include<iostream>
#include<vector>
using namespace std;
//计算逆序数_归并过程中计算

int count; 
vector<int> merge2(vector<int> v1,vector<int> v2){
	int i=0,j=0;
	vector<int> v;
	while(i!=v1.size()&&j!=v2.size()){
		if(v1[i]<=v2[j]){
			v.push_back(v1[i]);
			i++;
		}
		else {
			v.push_back(v2[j]);
			//如果左边某个数比右边大,它以及往后都是逆序数 
			count+=v1.size()-i;
			j++; 
		} 	
	}
	while(i<v1.size()){
		v.push_back(v1[i]);
		i++;
	}
				
	while(j<v2.size()){
		v.push_back(v2[j]);
		j++;
	}
	return v;	
	
} 
vector<int> getni(vector<int> v){
	if(v.size()==1)return v;
	vector<int>v1;
	for (int i = 0; i<=v.size() / 2 - 1; i++)
		v1.push_back(v[i]);
	vector<int>v2;
	for (int i = v.size() / 2; i<v.size(); i++)
		v2.push_back(v[i]);
	vector<int> v11 = getni(v1);
	vector<int> v22 = getni(v2);
	return merge2(v11,v22);
	
	
} 

void output(vector<int> v) {
	for (int i = 0; i<v.size(); i++)
		if (i != v.size() - 1)
			cout << v[i] << endl;
		else cout << v[i];

}
int main(){
	int n;
	vector<int> v;
	vector<int> result;
	cin>>n;
	
	while(n!=0){
		for(int i=0;i<n;i++){
			int a;
			cin>>a;
			v.push_back(a);
		}
		getni(v); 
		result.push_back(count);
		count=0; 
		v.clear();
		cin>>n;
	}
	output(result);
	return 0;
	
	//测试代码
	//int a[5]={2,4,1,3,5};
	
//	int a[7]={2, 7 , 1 , 4 , 5 , 3 , 9};
//	vector<int> test(a,a+7);
//	getni(test);
//	cout<<count; 
} 
