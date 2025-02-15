#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
using ll=long long;
struct Point{
	ll x,y;
	int n;
	bool operator< (const Point&a){
		return y==a.y?x<a.x:y<a.y;
	}
};
int T,N;
vector<Point> P;
ll ccw(const Point &a, const Point &b, const Point &c)
{
    return a.x*b.y+b.x*c.y+c.x*a.y-b.x*a.y-c.x*b.y-a.x*c.y;
}
ll dist(Point a, Point b)
{
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

bool comp(const Point &a, const Point &b){
	ll c=ccw(P[0],a,b);
	if(c==0){
		return dist(P[0],a)<dist(P[0],b);
	}
	return c>0;
}
bool dcomp(const Point &a, const Point &b){
	return dist(P[0],a)>dist(P[0],b);
}
stack<int> S;
int main(){
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	cin>>T;
	while(T--){
		cin>>N;
		P.resize(N);
		for(int i=0;i<N;++i){
			cin>>P[i].x>>P[i].y;
			P[i].n=i;
		}
		sort(P.begin(),P.end());
		sort(P.begin()+1,P.end(),comp);
		auto iter=P.begin()+1;
		for(;iter!=P.end();++iter){
			if(ccw(P[0],P[N-1],*iter)==0){
				break;
			}
		}
		sort(iter,P.end(),dcomp);
		for(auto e: P){
			cout<<e.n<<" ";
		}
		cout<<endl;
	}
}