#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int N;
	cin>>N;
	vector<int> v;
	for(int i=0;i<N;++i){
		int a;
		cin>>a;
		v.push_back(a);
	}
	sort(v.begin(), v.end(), greater<int>());
	int sum=-1;
	for(int i=0;i<=(v.size()-3);++i){
		if(v[i]<v[i+1]+v[i+2]){
			sum=v[i]+v[i+1]+v[i+2];
			break;
		}
	}
	cout<<sum;
}