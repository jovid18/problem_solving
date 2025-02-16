#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
using ll=long long;
const int MAX=2001;
int N;
ll ans;
struct Point{
	ll x,y,idx,oil;
};
bool chk[MAX];
Point mark;
int ccw(const Point &a, const Point &b, const Point &c){
	ll ret=a.x*b.y+b.x*c.y+c.x*a.y-b.x*a.y-c.x*b.y-a.x*c.y;
	if(ret>0) return 1;
	else if(ret==0) return 0;
	else return -1;
}
bool comp(const Point &a, const Point &b){
	int c=ccw(mark,a,b);
	if(c==0) return a.oil>b.oil;
	return c>0;
} 
vector<Point> P;
void sol(int now){
	vector<Point> Q;
	mark=P[now];
	for(auto e: P){
		if(e.y==mark.y)
			continue;
		else if(e.y>mark.y) Q.push_back(e); 
		else{
			ll cx=2*mark.x-e.x;
			ll cy=2*mark.y-e.y;
			Q.push_back({cx,cy,e.idx,e.oil});
		}
	}
	sort(Q.begin(),Q.end(),comp);
	for(auto &e:Q){
		if(chk[e.idx]) e.oil*=-1;
		else chk[e.idx]=true;
	}
	sort(Q.begin(),Q.end(),comp);
	ll oilsum=mark.oil;
	ans=max(ans,oilsum);
	for(auto e: Q){
		oilsum+=e.oil;
		ans=max(ans,oilsum);
	}
}
int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>N;
	for(int i=0;i<N;++i){
		int a,b,c;
		cin>>a>>b>>c;
		P.push_back({a,c,i,abs(b-a)});
		P.push_back({b,c,i,abs(b-a)});
	}
	for(int i=0;i<2*N;++i){
		memset(chk,0,sizeof(chk));
		sol(i);
	}
	cout<<ans;
}