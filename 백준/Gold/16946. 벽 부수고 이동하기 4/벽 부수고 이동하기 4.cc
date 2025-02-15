#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int x[4]={1,-1,0,0};
int y[4]={0,0,-1,1};
int N,M;
vector<vector<int>> seperate;
vector<vector<int>> reachsize;
vector<vector<bool>> checked;
void dfs(vector<vector<int>> v){
	int count=0;
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			if(v[i][j]==0&&!checked[i][j]){
				count++;
				checked[i][j]=true;
				queue<pair<int,int>> q;
				vector<pair<int,int>> s;
				q.push({i,j});
				int reach=1;
				while(!q.empty()){
					auto f=q.front();
					s.push_back(f);
					q.pop();
					for(int k=0;k<4;++k){
						int xi=f.first+x[k];
						int yi=f.second+y[k];
						if(0<=xi&&xi<N&&0<=yi&&yi<M&&v[xi][yi]==0&&!checked[xi][yi]){
							checked[xi][yi]=true;
							q.push({xi,yi});
							reach++;
						}
					}
				}
				for(auto e:s){
					seperate[e.first][e.second]=count;
					reachsize[e.first][e.second]=reach;
				}
			}
		}
	}
}
vector<vector<int>> g;
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>M;
	g.resize(N);
	for(int i=0;i<N;++i){
		g[i].resize(M);
		char a;
		for(int j=0;j<M;++j){
			cin>>a;
			g[i][j]=a-'0';
		}
	}
	seperate.assign(N,vector<int> (M,0));
	reachsize.assign(N,vector<int> (M,0));
	checked.assign(N,vector<bool> (M,0));
	dfs(g);
	
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			if(g[i][j]==0){
				cout<<0;
				continue;
			}
			vector<pair<int,int>> s;
			for(int k=0;k<4;++k){
				int xk=i+x[k];
				int yk=j+y[k];
				if(0<=xk&&xk<N&&0<=yk&&yk<M){
					s.push_back({seperate[xk][yk],reachsize[xk][yk]});
				}
			}
			sort(s.begin(),s.end());
			s.erase(unique(s.begin(),s.end()),s.end());
			int count=1;
			for(auto e:s){
				count+=e.second;
			}
			cout<<count%10;
		}
		cout<<'\n';
	}
}
