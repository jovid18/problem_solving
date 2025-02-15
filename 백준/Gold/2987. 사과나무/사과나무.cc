#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
using pdd=pair<double,double>;
vector<pdd> P(3);
double dist(pdd a,pdd b){
	return sqrt((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second));
}
double area(pdd a,pdd b,pdd c){
	return abs(a.first*(b.second-c.second)+b.first*(c.second-a.second)+c.first*(a.second-b.second))/2;
}
double ccw(pdd a,pdd b, pdd c) {
    return (b.first - a.first) * (c.second - a.second) - (c.first - a.first) * (b.second - a.second);
}
 
bool in(pdd a){
	if(ccw(P[0],P[1],a)<0||ccw(P[0],P[2],a)>0) return false;
	return ccw(P[1],P[2],a)>=0;
}
bool comp(pdd &a, pdd &b){
	double c=ccw(P[0],a,b);
	if(c==0){
		return dist(P[0],a)<dist(P[0],b);
	}
	return c>0;
}
int N;
pdd tree;
int main(){
	for(int i=0;i<3;++i){
		cin>>P[i].first>>P[i].second;
	}
	cout<<fixed;
	cout.precision(1);
	cout<<area(P[0],P[1],P[2])<<'\n';
	cout.unsetf(ios::fixed);
	sort(P.begin()+1,P.end(),comp);
	cin>>N;
	int ans=0;
	while(N--){
		cin>>tree.first>>tree.second;
		if(in(tree)) ans++;
	}
	cout<<ans;
}