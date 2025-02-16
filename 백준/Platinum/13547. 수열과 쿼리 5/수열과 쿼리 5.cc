#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
using ll=long long;
ll A[100000];
ll C[1000001];
ll R[100000];
int N,M,bs;
ll res;
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
	for(int i=0;i<N;++i){
		cin>>A[i];
	}
	bs=sqrt(N);
	cin>>M;
	Q.resize(M);
	for(int i=0;i<M;++i){
		Q[i].idx=i;
		int a,b;
		cin>>a>>b;
		a--;
		b--;
		Q[i].s=a;
		Q[i].f=b;
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
