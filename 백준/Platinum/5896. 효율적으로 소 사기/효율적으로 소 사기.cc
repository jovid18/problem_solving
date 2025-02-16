#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;
ll N,K,M;
vector<pll> V;
struct comp {
    bool operator()(pll a, pll b) { return a.first > b.first; }
};
priority_queue<pll,vector<pll>,comp> Q;
bool bycoup(const pll &a,const pll &b){
	if(a.second==b.second) return a.first<b.first;
	return a.second<b.second;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>K>>M;
	V.resize(N);
	for(int i=0;i<N;++i){
		cin>>V[i].first>>V[i].second;
	}
	sort(V.begin(),V.end(),bycoup);
	int cowbuy=0;
	for(int i=0;i<N;++i){
		if(i<K){
			if(V[i].second>M) break;
			M-=V[i].second;
			Q.push(V[i]);
			cowbuy++;
		}else{
			ll cost1=V[i].second+Q.top().first-Q.top().second;
			ll cost2=V[i].first;
			if(cost1>=cost2){
				if(M<cost2) continue;
				M-=cost2;
				cowbuy++;
			}else{
				if(M<cost1) continue;
				Q.pop();
				Q.push(V[i]);
				M-=cost1;
				cowbuy++;
			}
		}
	}
	cout<<cowbuy;
}