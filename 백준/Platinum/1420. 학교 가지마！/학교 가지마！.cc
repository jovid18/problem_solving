#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int N,M,S,T;
int x[4]={0,1,0,-1};
int y[4]={1,0,-1,0};
vector<int> A,B;
const int MAX_V=20001,INF=1e9,CYC=10000;
vector<int> adj[MAX_V];
int c[MAX_V][5];
int f[MAX_V][5];
int work[MAX_V];
int level[MAX_V];
bool in(int i, int j){
	if(i<0||j<0||i>=N||j>=M){
		return true;
	}
	return false;
}
vector<vector<char>> C;
int tonum(int i, int j,int s){
	if(s==0) return i*M+j;
	return CYC+i*M+j;
}

bool bfs(){
	fill(level,level+MAX_V,-1);
	level[S]=0;
	queue<int> q;
	q.push(S);
	while(!q.empty()){
		int now=q.front();
		q.pop();
		for(auto k:adj[now]){
			int e;
			if(now<CYC) e=now+A[k];
			else e=now+B[k];
			if(level[e]==-1&&c[now][k]>f[now][k]){
				level[e]=level[now]+1;
				q.push(e);
			}
		}
	}
	return level[T]!=-1;
}

int dfs(int now,int flow){
	if(now==T){
		return flow;
	}
	for(int &i=work[now];i<adj[now].size();++i){
		int n=adj[now][i];
		int e;
		if(now<CYC) e=now+A[n];
		else e=now+B[n];
		if(level[e]==(level[now]+1)&&c[now][n]-f[now][n]>0){
			int ret= dfs(e,min(c[now][n]-f[now][n],flow));
			if(ret>0){
				f[now][n]+=ret;
				f[e][n]-=ret;
				return ret;
			}
		}
	}
	return 0;
}

int main(){
	cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
	cin>>N>>M;
	if(N==1&&M==1){
		cout<<-1;
		return 0;
	}
	A={CYC-1,CYC-M,CYC+1,CYC+M,CYC};
	B={-CYC+1,-CYC+M,-CYC-1,-CYC-M,-CYC};
	int c1=0,c2=0;
	C.assign(N,vector<char> (M,'0'));
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			cin>>C[i][j];
			if(C[i][j]=='K'){
				S=tonum(i,j,0);
				c1++;
			}
			if(C[i][j]=='H'){
				T=tonum(i,j,1);
				c2++;
			}
		}
	}
	if(c1!=1||c2!=1){
		cout<<-1;
		return 0;
	}
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			int s=tonum(i,j,0);
			int t=tonum(i,j,1);
			c[s][4]=1;
			adj[s].push_back(4);
			adj[t].push_back(4);
		}
	}
	c[S][4]=INF;
	c[T-CYC][4]=INF;
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			if(C[i][j]=='#') continue;
			int s=tonum(i,j,1);
			for(int t=0;t<4;++t){
				int xi=i+x[t];
				int yi=j+y[t];
				if(in(xi,yi)) continue;
				if(C[xi][yi]=='#') continue;
				int f=tonum(xi,yi,0);
				if(s-CYC==S&&f+CYC==T){
					cout<<-1;
					return 0;
				}
				c[s][t]=1;
				adj[s].push_back(t);
				adj[f].push_back(t);
			}
		}
	}
	int ans=0;
	while(bfs()){
		fill(work,work+MAX_V,0);
		while(1){
			int flow=dfs(S,INF);
			if(flow==0) break;
			ans+=flow;
		}
	}
	cout<<ans;
}
