#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
using pdd=pair<double,double>;
vector<pdd> P(4);
double dist(pdd a,pdd b){
	return sqrt((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second));
}
double D[4][4];
int main(){
	for(int i=0;i<4;++i){
		cin>>P[i].first>>P[i].second;
	}
	double ans=100;
	for(int i=0;i<4;++i){
		for(int j=0;j<4;++j){
			D[i][j]=dist(P[i],P[j]);
		}
	}
	ans=min(ans,D[0][1]+D[1][2]+D[2][3]);
	ans=min(ans,D[0][1]+D[1][3]+D[3][2]);
	ans=min(ans,D[0][2]+D[2][1]+D[1][3]);
	ans=min(ans,D[0][2]+D[2][3]+D[3][1]);
	ans=min(ans,D[0][3]+D[3][1]+D[1][2]);
	ans=min(ans,D[0][3]+D[3][2]+D[2][1]);
	cout<<(int)ans;
}