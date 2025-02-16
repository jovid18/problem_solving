#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ull=unsigned long long;
ull MAX=1000000007;
int N;
vector<ull> P;
vector<ull> T(300000,0);
int main(){
	cin>>N;
	P.resize(N);
	for(int i=0;i<N;++i){
		cin>>P[i];
	}
	sort(P.begin(),P.end());
	for(int i=0;i<N;++i){
		P[i]%=MAX;
	}
	T[0]=1;
	for(int i=1;i<300000;++i){
		T[i]=(T[i-1]*2)%MAX;
	}
	ull ans=0;
	for(int i=N;i>=1;--i){
		ans+=P[i-1]*(T[i-1]-T[N-i]+MAX);
		ans%=MAX;	
	}
	cout<<ans;
}