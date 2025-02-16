#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N,M;
int x=0,y=0;
vector<int> v;
vector<int> h;
int main(){
	cin>>N>>M;
	v.resize(N);
	for(int i=0;i<N;++i){
		cin>>v[i];
	}
	if(M!=1){
		h.resize(M-1);
		for(int i=0;i<M-1;++i){
			cin>>h[i];
		}
	}
	auto iter=min_element(v.begin(),v.end());
	cout<<iter-v.begin()+1<<" "<<*iter+1;
}
