#include <iostream>
using namespace std;
int lx,ly,lz,x,y,z;
int dist(int x,int y){
	return x*x+y*y;
}
int main(){
	while(1){
		cin>>lx>>ly>>lz>>x>>y>>z;
		if(lx==0) break;
		if(x==0){
			cout<<dist(y,z)<<'\n';
			continue;
		}
		if(y==0){
			cout<<dist(x,z)<<'\n';
			continue;
		}
		if(z==0){
			cout<<dist(x,y)<<'\n';
			continue;
		}
		if(y==ly){
			
		}else if(x==lx){
			swap(lx,ly);
			swap(x,y);
		}else if(z==lz){
			swap(lz,ly);
			swap(z,y);
		}
		int l=1e9;
		l=min(l,dist(ly+x,z));
		l=min(l,dist(ly+z,x));
		if(lx*lx<=x*lx+z*ly){
			l=min(l,dist(lx+z,lx+ly-x));
		}
		if(lz*lz<=z*lz+x*ly){
			l=min(l,dist(lz+x,lz+ly-z));
		}
		cout<<l<<'\n';
	}
}