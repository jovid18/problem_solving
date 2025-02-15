#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> a;
vector<int> b;
int N,M;

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	a.resize(N);
	for(int i=0;i<N;++i){
		cin>>a[i];
	}
	cin>>M;
	b.resize(M);
	for(int i=0;i<M;++i){
		cin>>b[i];
	}
	sort(a.begin(),a.end());
	for(int i=0;i<M;++i){
		auto iter=lower_bound(a.begin(),a.end(),b[i]);
		if(iter!=a.end()&&*iter==b[i]){
			cout<<1<<" ";
		}else{
			cout<<0<<" ";
		}
	}
}