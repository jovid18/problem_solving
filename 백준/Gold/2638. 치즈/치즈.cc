#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N,M;
vector<vector<int>> cheese;
vector<vector<bool>> exterior;
queue<pair<int,int>> process;
int finish;
int count;
void BFS(vector<vector<int>> & cheese, vector<vector<bool>> exterior,queue<pair<int,int>> process){
	
	while(!process.empty()){
		int size=process.size();
		for(int i=0;i<size;++i){
			int x=process.front().first;
			int y=process.front().second;
			if(x-1>=0&&cheese[x-1][y]==0&&!exterior[x-1][y]){
				exterior[x-1][y]=true;
				process.push(make_pair(x-1,y));
			}
			if(y-1>=0&&cheese[x][y-1]==0&&!exterior[x][y-1]){
				exterior[x][y-1]=true;
				process.push(make_pair(x,y-1));
			}
			if(x+1<N&&cheese[x+1][y]==0&&!exterior[x+1][y]){
				exterior[x+1][y]=true;
				process.push(make_pair(x+1,y));
			}
			if(y+1<M&&cheese[x][y+1]==0&&!exterior[x][y+1]){
				exterior[x][y+1]=true;
				process.push(make_pair(x,y+1));
			}
			process.pop();
		}
	}
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			if(cheese[i][j]==1){
				int exteriorcount=0;
				if(i-1>=0&&exterior[i-1][j]){
					exteriorcount++;
				}
				if(j-1>=0&&exterior[i][j-1]){
					exteriorcount++;
				}
				if(i+1<N&&exterior[i+1][j]){
					exteriorcount++;
				}
				if(j+1<M&&exterior[i][j+1]){
					exteriorcount++;
				}
				if(exteriorcount>=2){
					cheese[i][j]=0;
				}
			}
		}
	}
	int cheesenum=0;
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			if(cheese[i][j]==1){
				cheesenum++;
			}
		}
	}
	if(cheesenum==0){
		finish++;
	}
}

int main(){
	cin>>N>>M;
	cheese.resize(N);
	bool cheesecheck=false;
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			cheese[i].resize(M);
			cin>>cheese[i][j];
			if(!cheesecheck&&cheese[i][j]==1){
				cheesecheck=true;
			}
		}
	}
	if(!cheesecheck) finish++;
	exterior.assign(N,vector<bool> (M,false));
	process.push(make_pair(0,0));
	process.push(make_pair(0,M-1));
	process.push(make_pair(N-1,0));
	process.push(make_pair(N-1,M-1));
	exterior[0][0]=true;
	exterior[0][M-1]=true;
	exterior[N-1][0]=true;
	exterior[N-1][M-1]=true;

	while(finish!=1){
		BFS(cheese,exterior,process);
		count++;
	}
	cout<<count;
	
}