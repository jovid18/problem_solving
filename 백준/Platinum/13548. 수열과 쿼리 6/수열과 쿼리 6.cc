#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
using ll=long long;
ll A[100001];
ll C[100001];
ll H[100001];
ll R[100001];
int N,M,bs;
struct q{
	int idx,s,f;
};
bool comp(const q &a,const q &b){
	return (a.s/bs)==(b.s/bs)?a.f<b.f:(a.s/bs)<(b.s/bs);
}
vector<q> Q;
int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>N;
	for(int i=1;i<=N;++i){
		cin>>A[i];
	}
	bs=sqrt(N);
	cin>>M;
	Q.resize(M);
	for(int i=0;i<M;++i){
		Q[i].idx=i;
		int a,b;
		cin>>a>>b;
		Q[i].s=a;
		Q[i].f=b;
	}
	sort(Q.begin(),Q.end(),comp);
	ll s=Q[0].s,f=Q[0].f,Max=0;
	for(int i=s;i<=f;++i){
		if(C[A[i]]!=0) H[C[A[i]]]--; 
		C[A[i]]++;
		H[C[A[i]]]++;
		Max=max(Max,C[A[i]]);
	}
	R[Q[0].idx]=Max;
	for(int i=1;i<M;++i){
		while(s<Q[i].s){
			H[C[A[s]]]--;
			if(Max==C[A[s]]&&H[C[A[s]]]==0) Max--;
			C[A[s]]--;
			H[C[A[s]]]++;
			s++;
		}
		while(Q[i].s<s){
			s--;
			if(C[A[s]]!=0) H[C[A[s]]]--; 
			C[A[s]]++;
			H[C[A[s]]]++;
			Max=max(Max,C[A[s]]);
		}
		while(f<Q[i].f){
			f++;
			if(C[A[f]]!=0) H[C[A[f]]]--; 
			C[A[f]]++;
			H[C[A[f]]]++;
			Max=max(Max,C[A[f]]);
		}
		while(Q[i].f<f){
			H[C[A[f]]]--;
			if(Max==C[A[f]]&&H[C[A[f]]]==0) Max--;
			C[A[f]]--;
			H[C[A[f]]]++;
			f--;
		}
		R[Q[i].idx]=Max;
	}
	for(int i=0;i<M;++i){
		cout<<R[i]<<'\n';
	}
}
