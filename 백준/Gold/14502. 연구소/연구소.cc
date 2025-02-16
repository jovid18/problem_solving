#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N,M;
vector<vector<int>> lab;
queue<pair<int,int>> process;
vector<int> check(3,-1);
int MAX=0;
int simulation(vector<vector<int>> L,queue<pair<int,int>> P){
	while(!P.empty()){
		int size=P.size();
		for(int i=0;i<size;++i){
			int x=P.front().first;
			int y=P.front().second;
			if(x-1>=0&&L[x-1][y]==0){
				L[x-1][y]=2;
				P.push(make_pair(x-1,y));
			}
			if(y-1>=0&&L[x][y-1]==0){
				L[x][y-1]=2;
				P.push(make_pair(x,y-1));
			}
			if(x+1<N&&L[x+1][y]==0){
				L[x+1][y]=2;
				P.push(make_pair(x+1,y));
			}
			if(y+1<M&&L[x][y+1]==0){
				L[x][y+1]=2;
				P.push(make_pair(x,y+1));
			}
			P.pop();
		}
	}
	int count=0;
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			if(L[i][j]==0){
				count++;
			}
		}
	}
	return count;
}

void virus(int count,vector<vector<int>> L,queue<pair<int,int>> P){
	for(int i=0;i<N*M;++i){
		for(int j=i+1;j<N*M;++j){
			for(int k=j+1;k<N*M;++k){
				int ix=i/M;
				int iy=i%M;
				int jx=j/M;
				int jy=j%M;
				int kx=k/M;
				int ky=k%M;
				if(L[ix][iy]==0&&L[jx][jy]==0&&L[kx][ky]==0){
					L[ix][iy]=1;
					L[jx][jy]=1;
					L[kx][ky]=1;
					int now=simulation(L, P);
					MAX=max(MAX,now);
					L[ix][iy]=0;
					L[jx][jy]=0;
					L[kx][ky]=0;
				}
			}
		}
	}
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>M;
	lab.resize(N);
	for(int i=0;i<N;++i){
		lab[i].resize(M);
		for(int j=0;j<M;++j){
			cin>>lab[i][j];
			if(lab[i][j]==2){
				process.push(make_pair(i,j));
			}
		}
	}
	virus(0,lab,process);
	cout<<MAX;
}
