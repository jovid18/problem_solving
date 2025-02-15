#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long N,M;
using pll=pair<long long, long long>;
vector<pll> P;
bool update[300001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>M;
	P.resize(M);
	for(int i=0;i<M;++i){
		cin>>P[i].second;
	}
	for(int i=0;i<M;++i){
		cin>>P[i].first;
	}
	if(N==M){
		for(int i=0;i<M;++i){
			if(P[i].first!=P[i].second){
				cout<<-1;
				return 0;
			}
		}
		cout<<0;
		return 0;
	}
	sort(P.begin(),P.end());
	bool rev=false;
	for(int i=0;i<M;++i){
		if(i>0&&P[i].first==P[i-1].first){
			cout<<-1;
			return 0;
		}
		if(i>0&&P[i].second<P[i-1].second){
			for(int j=i;j<M;++j) P[j].second+=N;
		}
		if(P[i].first>P[i].second){
			for(int j=0;j<M;++j) P[j].second+=N;
		}
		if(i>0&&(P[0].second+N<=P[i].second)){
			cout<<-1;
			return 0;
		}
	}
	if(P[0].second+N<=P[M-1].second){
		cout<<-1;
		return 0;
	}
	long long ans=0;
	for(int i=0;i<M;++i) ans+=P[i].second-P[i].first;
	cout<<ans;
}