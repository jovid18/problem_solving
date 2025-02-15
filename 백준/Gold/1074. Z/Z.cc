#include <iostream>
#include <cmath>
using namespace std;

int z(long long n,int x, int y){
	if(n==2){
		if(x==0&&y==0){
			return 0;
		}else if(x==0&&y==1){
			return 1;
		}else if(x==1&&y==0){
			return 2;
		}else{
			return 3;
		}
	}else{
		if(0<=x&&x<n/2&&0<=y&&y<n/2){
			return z(n/2,x,y);
		}else if(0<=x&&x<n/2&&n/2<=y&&y<n){
			return n*n/4+z(n/2,x,y-n/2);
		}else if(n/2<=x&&x<n&&0<=y&&y<n/2){
			return n*n/2+z(n/2,x-n/2,y);
		}else{
			return n*n*3/4+z(n/2,x-n/2,y-n/2);
		}
	}
}

int main(){
	int n;
	int x,y;
	cin>>n>>x>>y;
	long long N=pow(2,n);
	cout<<z(N,x,y);
}
