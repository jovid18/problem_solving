#include <iostream>
#include <vector>
using namespace std;
int N,M;
vector<int> c;
vector<int> m;
vector<long long> mmax;
int main(){
	cin>>N>>M;
	int cmax=0;
	for(int i=0;i<N;++i){
		int a;
		cin>>a;
		m.push_back(a);
	}
	for(int i=0;i<N;++i){
		int a;
		cin>>a;
		cmax+=a;
		c.push_back(a);
	}
	mmax.assign(cmax+1,0);
	for(int i=0;i<N;++i){
		for(int j=cmax;j>=c[i];--j){
			mmax[j]=max(mmax[j],mmax[j-c[i]]+m[i]);
		}
	}
	for(int i=0;i<=cmax;++i){
		if(mmax[i]>=M){
			cout<<i;
			break;
		}
	}
}