#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
long double Vecsize(long long x, long long y){
	return sqrt((x*x)+(y*y));
}
int point [20][2]={0};
int T,N;
long double maxdist;
int sumx,sumy;
int nowx,nowy;
void dfs(int start, int count){
	if(count==N/2){
		maxdist=min(maxdist,Vecsize(sumx-2*nowx,sumy-2*nowy));
		return;
	}
	for(int i=start;i<N;++i){
		nowx+=point[i][0];
		nowy+=point[i][1];
		dfs(i+1,count+1);
		nowx-=point[i][0];
		nowy-=point[i][1];
	}
}
int main(){
	cout.precision(16);
	cin>>T;
	while(T--){
		nowx=0;
		nowy=0;
		sumx=0;
		sumy=0;
		cin>>N;
		for(int i=0;i<N;++i){
			for(int j=0;j<2;++j){
				cin>>point[i][j];
				if(j==0) sumx+=point[i][j];
				if(j==1) sumy+=point[i][j];
			}
		}
		maxdist=3000000;
		dfs(0,0);
		cout<<maxdist<<endl;
	}
}
