#include <vector>
#include <iostream>
#include <cmath>
using namespace std;
vector<pair<int,int>> point;
int N;

long double area(long long x1,long long  y1, long long x2,long long y2, long long x3, long long y3){
	long double n=(long double)(x1*y2+x2*y3+x3*y1-x1*y3-x3*y2-x2*y1)/2;
	return n;
}

int main(){
	cin>>N;
	point.resize(N);
	for(int i=0;i<N;++i){
		long long x,y;
		cin>>x>>y;
		point[i]={x,y};
	}
	long double ans=0;
	for(int i=1;i<N-1;++i){
		ans+=area(point[0].first , point[0].second , point[i].first , point[i].second, point[i+1].first, point[i+1].second);
	}
	cout.precision(1);
	cout<<fixed<<abs(ans);
}
