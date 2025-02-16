#include <vector>
#include <iostream>
#include <cmath>
using namespace std;
using pii=pair<int,int>;
int dist(pii a, pii b){
	return abs(a.first-b.first)+abs(a.second-b.second);
}
int N,W;
vector<pii> C;
vector<vector<int>> DP,R;
int find(int x,int y){
	if(x==W||y==W){
		return DP[x][y]=0;
	} 
	if(DP[x][y]!=-1){
		return DP[x][y];
	}
	int now=max(x,y)+1;
	int dist1,dist2;
	if(x==0){
		dist1=dist({1,1},C[now])+find(now,y);
	}else{
		dist1=dist(C[x],C[now])+find(now,y);
	}
	if(y==0){
		dist2=dist({N,N},C[now])+find(x,now);
	}else{
		dist2=dist(C[y],C[now])+find(x,now);
	}
	if(dist1<=dist2){
		R[x][y]=1;
	}else{
		R[x][y]=2;
	}
	return DP[x][y]=min(dist1,dist2);
}
void print(int x,int y){
	if(x==W||y==W) return;
	int now=max(x,y)+1;
	if(R[x][y]==1){
		cout<<1<<'\n';
		print(now,y);
	}else{
		cout<<2<<'\n';
		print(x,now);
	}
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>W;
	DP.assign(W+1,vector<int>(W+1,-1));
	R.assign(W+1,vector<int>(W+1,-1));
	C.resize(W+1);
	for(int i=1;i<=W;++i){
		cin>>C[i].first>>C[i].second;
	}
	cout<<find(0,0)<<'\n';
	print(0,0);
}