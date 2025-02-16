#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
using ld=long double;
ld N,x,y,z,r;
vector<ld> X,Y,Z;
ld dist(ld a, ld b, ld c){
	return (x-a)*(x-a)+(y-b)*(y-b)+(z-c)*(z-c);
}
int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>N;
	X.resize(N);
	Y.resize(N);
	Z.resize(N);
	for(int i=0;i<N;++i){
		cin>>X[i]>>Y[i]>>Z[i];
		x+=X[i];
		y+=Y[i];
		z+=Z[i];
	}
	x/=N;
	y/=N;
	z/=N;
	ld ret=0.1;
	for(int i=0;i<100000;++i){
		r=-1;
		int maxj=-1;
		for(int j=0;j<N;++j){
			ld d=dist(X[j],Y[j],Z[j]);
			if(d>r){
				r=d;
				maxj=j;
			}
		}
		x+=(X[maxj]-x)*ret;
		y+=(Y[maxj]-y)*ret;
		z+=(Z[maxj]-z)*ret;
		ret*=0.999;
	}
	cout<<fixed;
	cout.precision(2);
	cout<<sqrt(r);
}