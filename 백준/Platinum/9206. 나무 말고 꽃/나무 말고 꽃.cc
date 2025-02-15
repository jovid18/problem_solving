#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
using ld=long double;
const ld pi = 3.14159265358979;
ld S=100000;
ld V,a,b,h;
int N;
ld func(ld x){
	ld f= a*exp(-x*x)+b*sqrt(x);
	return pi*f*f;
}
vector<pair<ld,int>> F;
int main(){
	cin>>V>>N;
	F.resize(N);
	for(int i=0;i<N;++i){
		cin>>a>>b>>h;
		ld sum=0;
		for(ld j=0;j<S;++j){
			ld bl=h*j/S;
			ld bh=h*(j+1)/S;
			sum+=(h/(6*S))*(func(bl)+func(bh)+4*func((bl+bh)/2));
		}
		F[i]={abs(sum-V),i};
	}
	sort(F.begin(),F.end());
	cout<<F[0].second;
}

