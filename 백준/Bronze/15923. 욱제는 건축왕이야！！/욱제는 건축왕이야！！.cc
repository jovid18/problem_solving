#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
const double pi = 3.14159265358979;
using pii= pair<int,int>;
vector<pii> P;
int N;
int l(pii a, pii b){
	return abs(a.first-b.first)+abs(a.second-b.second);
}
int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>N;
	P.resize(N);
	for(int i=0;i<N;++i){
		cin>>P[i].first>>P[i].second;
	}
	int ans=0;
	for(int i=0;i<N-1;++i){
		ans+=l(P[i],P[i+1]);
	}
	ans+=l(P[0],P[N-1]);
	cout<<ans;
}