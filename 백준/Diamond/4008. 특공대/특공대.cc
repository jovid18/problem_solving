#include <iostream>
#include <vector>
using namespace std;
using ll=long long;
vector<ll> S,PS,DP;
struct L{
	ll a,b;
	double c_x;
	L(ll av,ll bv,double cv=0):a(av),b(bv),c_x(cv) {}
};
double cross(const L& L1,const L& L2){
	return (L2.b-L1.b)/(L1.a-L2.a);
}
int BS(vector<L> &LS,ll value){
	int low=0,high=LS.size()-1,pos=0;
	while(low<=high){
		int mid=(low+high)/2;
		if(LS[mid].c_x<value){
			pos=mid;
			low=mid+1;
		}else high=mid-1;
	}
	return pos;
}
ll a,b,c;
ll f(ll x){
	return a*x*x+b*x+c;
}
ll A(int i){
	return -2*a*PS[i];
}
ll B(int j){
	return PS[j];
}
ll C(int j){
	return DP[j]+a*PS[j]*PS[j]-b*PS[j];
}
ll D(int i){
	return f(PS[i]);
}
int N;
vector<L> LS;
int main(){
	cin>>N>>a>>b>>c;
	S.resize(N);
	PS.resize(N+1);
	DP.assign(N+1,-1);
	for(int i=0;i<N;++i){
		cin>>S[i];
	}
	PS[0]=S[0];
	for(int i=1;i<=N;++i){
		PS[i]=S[i-1]+PS[i-1];
	}
	DP[0]=0;
	for(int i=1;i<=N;++i){
		L now(A(i-1),C(i-1));
		while(LS.size()>=1){
			now.c_x=cross(now,LS.back());
			if(now.c_x<LS.back().c_x) LS.pop_back();
			else break;
		}
		LS.push_back(now);
		int pos=BS(LS,B(i));
		DP[i]=LS[pos].a*B(i)+LS[pos].b+D(i);
	}
	cout<<DP[N];
}