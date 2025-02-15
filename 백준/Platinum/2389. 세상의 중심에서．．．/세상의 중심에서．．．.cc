#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
using pdd=pair<long double,long double>;
int N;
vector<pdd> V;
struct circle{
	pdd C;
	long double R;
};
long double dist(pdd a, pdd b){
	auto dx=a.first-b.first,dy=a.second-b.second;
	return sqrt(dx*dx+dy*dy);
}
pdd center(pdd a, pdd b){
	return {(a.first+b.first)/2,(a.second+b.second)/2};
}
pdd center(pdd a, pdd b, pdd c){
	long double x1=a.first,y1=a.second,x2=b.first,y2=b.second,x3=c.first,y3=c.second;
	long double xy21=x2*x2-x1*x1+y2*y2-y1*y1;
	long double xy23=x2*x2-x3*x3+y2*y2-y3*y3;
	long double x12=x1-x2;
	long double x32=x3-x2;
	long double y12=y1-y2;
	long double y32=y3-y2;
	return {-(xy21*y32-xy23*y12)/(2*x12*y32-2*x32*y12),-(xy21*x32-xy23*x12)/(2*y12*x32-2*y32*x12)};
}
int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>N;
	V.resize(N);
	for(int i=0;i<N;++i){
		cin>>V[i].first>>V[i].second;
	}
	random_shuffle(V.begin(),V.end());
	pdd anscen={0,0};
	long double ansr=0;
	for(int i=0;i<N;++i){
		if(dist(anscen,V[i])<=ansr) continue;
		anscen=V[i],ansr=0;
		for(int j=0;j<i;++j){
			if(dist(anscen,V[j])<=ansr) continue;
			anscen=center(V[i],V[j]);
			ansr=dist(anscen,V[i]);
			for(int k=0;k<j;++k){
				if(dist(anscen,V[k])<=ansr) continue;
				anscen=center(V[i],V[j],V[k]);
				ansr=dist(anscen,V[i]);
			}
		}
	}
	cout.precision(15);
	cout<<anscen.first<<" "<<anscen.second<<" "<<ansr;
}