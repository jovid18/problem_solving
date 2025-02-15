#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;
using pii=pair<int,int>;
struct Point{
	int d,x,y;
};
struct comp {
	bool operator()(const Point& p1, const Point& p2) {
		if(p1.d==p2.d){
			if(p1.x==p2.x){
				return p1.y>p2.y;
			}else{
				return p1.x>p2.x;
			}
		}
		return p1.d>p2.d;
	}
};
int N,T;
int x[4]={-1,0,0,1};
int y[4]={0,-1,1,0};
bool in(int a,int b){
	return 0<=a&&0<=b&&a<N&&b<N;
}
bool visited[21][21];
pii siz={2,2},pos;
vector<vector<int>> M;
priority_queue<Point,vector<Point>,comp> q;
int bfs(){
	auto ipos=q.top();
	auto fpos=ipos;
	while(!q.empty()){
		auto now=q.top();
		int nowd=now.d;
		int nowx=now.x;
		int nowy=now.y;
		if(M[nowx][nowy]!=0&&M[nowx][nowy]<siz.first){
			fpos={nowd,nowx,nowy};
			pos={nowx,nowy};
			M[nowx][nowy]=0;
			if(siz.second!=1) siz.second--;
			else{
				siz.first++;
				siz.second=siz.first;
			}
			break;
		}
		q.pop();
		for(int i=0;i<4;++i){
			int xi=nowx+x[i];
			int yi=nowy+y[i];
			if(in(xi,yi)&&!visited[xi][yi]&&M[xi][yi]<=siz.first){
				q.push({nowd+1,xi,yi});
				visited[xi][yi]=true;
			}
		}
	}
	return fpos.d;
}
int main(){
	cin>>N;
	M.assign(N,vector<int> (N,0));
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			cin>>M[i][j];
			if(M[i][j]==9){
				pos={i,j};
				M[i][j]=0;
			} 
		}
	}
	while(1){
		memset(visited,0,sizeof(visited));
		visited[pos.first][pos.second]=true;
		while(!q.empty()){
			q.pop();
		}
		q.push({0,pos.first,pos.second});
		int result=bfs();
		T+=result;
		if(!result) break;
	}
	cout<<T;
}