#include <iostream>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
#define ff first
#define ss second
using ll=long long;
using pll=pair<ll,ll>;
struct L{
	pll tp;
	int idx;
	pll isc;
};
int N,M;
ll minX,maxX;
vector<L> LS, V;
vector<pll> Q;
bool comp(L x, L y){
	auto a=x.tp, b=y.tp;
	if((a.ss-a.ff)==(b.ss-b.ff)) return a.ff<b.ff;
	return (a.ff-a.ss)<(b.ff-b.ss);
}
pll cross(pll x ,pll y){
	ll a=x.ff,b=x.ss,c=y.ff,d=y.ss;
	return {minX*(b-d)+maxX*(c-a),b+c-a-d};
}
int BS(vector<L>& arr,pll x){
	int low = 0, high = arr.size() - 1;
    while(low +1< high){
    	int mid = (low + high) / 2;
    	if(x.ss*arr[mid-1].isc.ff<x.ff*arr[mid-1].isc.ss&&x.ff*arr[mid].isc.ss<=x.ss*arr[mid].isc.ff) return arr[mid].idx;
        if(x.ff*arr[mid-1].isc.ss<=arr[mid-1].isc.ff*x.ss) high=mid;
        else low=mid+1;
    }
    if(x.ff*arr[low].isc.ss<=x.ss*arr[low].isc.ff) return arr[low].idx;
    return arr[high].idx;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>maxX>>minX>>N;
	LS.resize(N);
	for(int i=0;i<N;++i){
		cin>>LS[i].tp.ff>>LS[i].tp.ss;
		LS[i].idx=i+1;
	}
	sort(LS.begin(),LS.end(),comp);
	V.push_back(LS.front());
	V[0].isc.ff=minX;
	V[0].isc.ss=1;
	for(int i=1;i<N;++i){
		if(LS[i].tp.ss>=V.back().tp.ss) continue;
		while(V.size()>=1){
			LS[i].isc=cross(V.back().tp,LS[i].tp);
			if(LS[i].isc.ff*V.back().isc.ss<=V.back().isc.ff*LS[i].isc.ss) V.pop_back();
			else break;
		}
		V.push_back(LS[i]);
		if(V.size()==1){
			V[0].isc.ff=minX;
			V[0].isc.ss=1;
		}
	}
	for(int i=0;i+1<V.size();++i) V[i].isc=cross(V[i].tp,V[i+1].tp);
	V.back().isc={maxX,1};
	cin>>M;
	Q.resize(M);
	for(int i=0;i<M;++i){
		double x;
		cin>>x;
		x*=1000;
		Q[i]={1000LL*(minX+maxX)-llround(x),1000};
	}
	for(auto e:Q){
		if(e.ff*V[0].isc.ss<=V[0].isc.ff*e.ss||V.size()	<=1) cout<<V[0].idx<<'\n';
		else{
			if(V.size()==2) cout<<V[1].idx<<'\n';
			else cout<<BS(V,e)<<'\n';
		}
	}
}