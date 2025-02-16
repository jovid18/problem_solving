#include <iostream>
#include <vector>
using namespace std;
int N;
vector<vector<bool>> chess;
int xs[]={1,1,-1,-1};
int ys[]={1,-1,1,-1};
bool in(int x, int y){
	return(0<=x&&x<N&&0<=y&&y<N);
}
int max1=0;
int max2=0;
void dfs(int n, int start,vector<vector<bool>> &c,bool s){
	auto d=c;
	int x=start/N;
	int y=start%N;
	if(s){
		while((x+y)%2!=0){
			start++;
			x=start/N;
			y=start%N;
		}
		if(start>=N*N){
			max1=max(max1,n);
			return;
		}
		bool select=false;
		if(c[x][y]){
			c[x][y]=false;
			select=true;
			for(int j=0;j<4;++j){
				int xj=x+xs[j];
				int yj=y+ys[j];
				while(in(xj,yj)){
					if(c[xj][yj]){
						c[xj][yj]=false;
					}
					xj+=xs[j];
					yj+=ys[j];
				}
			}
		}
		start++;
		while((x+y)%2!=0){
			start++;
			x=start/N;
			y=start%N;
		}
		if(select){
			dfs(n+1,start,c,s);
		}
		dfs(n,start,d,s);
		c=d;
	}else{
		while((x+y)%2==0){
			start++;
			x=start/N;
			y=start%N;
		}
		if(start>=N*N){
			max2=max(max2,n);
			return;
		}
		bool select=false;
		if(c[x][y]){
			c[x][y]=false;
			select=true;
			for(int j=0;j<4;++j){
				int xj=x+xs[j];
				int yj=y+ys[j];
				while(in(xj,yj)){
					if(c[xj][yj]){
						c[xj][yj]=false;
					}
					xj+=xs[j];
					yj+=ys[j];
				}
			}
		}
		start++;
		while((x+y)%2==0){
			start++;
			x=start/N;
			y=start%N;
		}
		if(select){
			dfs(n+1,start,c,s);
		}
		dfs(n,start,d,s);
		c=d;
	}
}

int main(){
	cin>>N;
	chess.resize(N);
	for(int i=0;i<N;++i){
		chess[i].resize(N);
		for(int j=0;j<N;++j){
			bool s;
			cin>>s;
			chess[i][j]=s;
		}
	}
	dfs(0,0,chess,true);
	dfs(0,0,chess,false);
	cout<<max1+max2;
}