#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
using ll=long long;
struct point{
	ll x,y,v;
};
ll N,X=0,ans=-1e16;
vector<point> P;
void inorder(int t){
	if(t>N) return;
	inorder(2*t);
	P[t-1].x=X++;
	inorder(2*t+1);
}
bool xcomp(const point &a,const point &b){
	if(a.x==b.x) return a.y<b.y;
	return a.x<b.x;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	P.resize(N);
	for(int i=1;i<=N;++i){
		cin>>P[i-1].v;
		P[i-1].y=log2(i);
	}
	inorder(1);
	sort(P.begin(),P.end(),xcomp);
	int h=log2(N);
	for(int i=0;i<=h;++i){
		for(int j=i;j<=h;++j){
			ll init=-1e16;
			for(int k=0;k<N;++k){
				if(P[k].y<i||P[k].y>j) continue;
				if(init==-1e16){
					init=max(init,P[k].v);
				}else{
					init=max((ll)0,init)+P[k].v;
				}
				ans=max(ans,init);
			}
		}
	}
	cout<<ans;
}
