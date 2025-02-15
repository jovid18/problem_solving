# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
vector<int> X,O;
int A[1000001];
int C[1000001];
int R[1000001];
int N,M,bs;
int res;
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
	O.resize(N+1);
	for(int i=1;i<=N;++i){
		cin>>O[i];
	}
	X=O;
	sort(X.begin(),X.end());
	X.erase(unique(X.begin(),X.end()),X.end());
	for(int i=1;i<=N;++i){
		A[i]=lower_bound(X.begin(),X.end(),O[i])-X.begin();
	}
	bs=sqrt(N);
	cin>>M;
	Q.resize(M);
	for(int i=0;i<M;++i){
		cin>>Q[i].s>>Q[i].f;
		Q[i].idx=i;
	}
	sort(Q.begin(),Q.end(),comp);
	int s=Q[0].s,f=Q[0].f;
	for(int i=s;i<=f;++i){
		if(C[A[i]]==0) res++;
		C[A[i]]++;
	}
	R[Q[0].idx]=res;
	for(int i=1;i<M;++i){
		while(s<Q[i].s){
			if(C[A[s]]==1) res--;
			C[A[s]]--;
			s++;
		}
		while(Q[i].s<s){
			s--;
			if(C[A[s]]==0) res++;
			C[A[s]]++;
		}
		while(f<Q[i].f){
			f++;
			if(C[A[f]]==0) res++;
			C[A[f]]++;
		}
		while(Q[i].f<f){
			if(C[A[f]]==1) res--;
			C[A[f]]--;
			f--;
		}
		R[Q[i].idx]=res;
	}
	for(int i=0;i<M;++i){
		cout<<R[i]<<'\n';
	}
}
