#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int N,A;
struct crops{
	int x,y,w;
};
bool comp(crops &a,crops &b){
	return a.x*a.x+a.y*a.y<b.x*b.x+b.y*b.y;
}
double todist(crops &a){
	return sqrt(a.x*a.x+a.y*a.y);
}
double a,b,c;
double func(double x){
	return a*x*x+b*x+c;
}
vector<crops> C;
vector<double> R,W,WR;

int main(){
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	cin>>N>>A;
	C.resize(N);
	for(int i=0;i<N;++i){
		cin>>C[i].x>>C[i].y>>C[i].w;
	}
	sort(C.begin(),C.end(),comp);
	R.push_back(0);
	W.push_back(0);
	WR.push_back(0);
	for(int i=0;i<N;++i){
		double r=todist(C[i]);
		R.push_back(r);
		W.push_back(C[i].w+W[i]);
		WR.push_back(r*C[i].w+WR[i]);
	}
	R.push_back(1e9);
	a=-A;
	double ans=0;
	for(int i=0;i<=N;++i){
		b=W[i];
		c=-WR[i];
		ans=max(ans,func(R[i]));
		ans=max(ans,func(R[i+1]));
		double mid=-b/(2*a);
		if(R[i]<=mid&&mid<=R[i+1]){
			ans=max(ans,func(mid));
		}
	}
	cout.precision(14);
	cout<<ans;
}