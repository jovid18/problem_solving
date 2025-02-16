#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin>>N;
	vector<int> num;
	for(int i=0;i<N;++i){
		int a;
		cin>>a;
		num.push_back(a);
	}
	vector<int> orig=num;
	sort(num.begin(),num.end());
	num.erase(unique(num.begin(),num.end()),num.end());
	for(int i=0;i<N;++i){
		int a=orig[i];
		auto iter=lower_bound(num.begin(),num.end(),a);
		cout<<iter-num.begin()<<" ";
	}
}