#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
using pdd=pair<double,double>;
vector<pdd> P;
int N;
double dist(pdd a, pdd b){
	double x=pow(abs(a.first-b.first),2);
	double y=pow(abs(a.second-b.second),2);
	return sqrt(x+y);
}
vector<pair<double,int>> V;

int main(){
	cin>>N;
	P.resize(N);
	for(int i=0;i<N;++i){
		double a,b;
		cin>>a>>b;
		P[i]={a,b};
	}
	for(int i=0;i<N;++i){
		double D=0;
		for(int j=0;j<N;++j){
			D=max(D,dist(P[i],P[j]));
		}
		V.push_back({D,i});
	}
	sort(V.begin(),V.end());
	int n=V[0].second;
	cout<<P[n].first<<" "<<P[n].second;
}