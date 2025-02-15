#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <deque>
using namespace std;
using ll=long long;
ll W,H,K,N,M;
vector<ll> X,Y,RX,RY;
int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>W>>H>>K;
	cin>>N;
	Y.push_back(0);
	for(int i=0;i<N;++i){
		int a;
		cin>>a;
		Y.push_back(a);
	}
	Y.push_back(H);
	cin>>M;
	X.push_back(0);
	for(int i=0;i<M;++i){
		int a;
		cin>>a;
		X.push_back(a);
	}
	X.push_back(W);
	for(int i=0;i+1<Y.size();++i){
		RY.push_back(Y[i+1]-Y[i]);
	}
	for(int i=0;i+1<X.size();++i){
		RX.push_back(X[i+1]-X[i]);
	}
	sort(RX.begin(),RX.end());
	sort(RY.begin(),RY.end());
	ll ans=0;
	for(ll i=0;i<RX.size();){
		ll ycnt=upper_bound(RY.begin(),RY.end(),K/RX[i])-RY.begin();
		ll xcnt=upper_bound(RX.begin(),RX.end(),RX[i])-lower_bound(RX.begin(),RX.end(),RX[i]);
		i+=xcnt;
		ans+=xcnt*ycnt;
	}
	cout<<ans;
}