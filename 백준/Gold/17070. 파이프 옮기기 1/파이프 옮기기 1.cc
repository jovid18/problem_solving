#include <iostream>
#include <vector>
using namespace std;

int main(){
	int N;
	cin>>N;
	vector<vector<int>> wall(N,vector<int>(N,0));
	vector<vector<int>> garo(N,vector<int>(N,0));
	vector<vector<int>> daeg(N,vector<int>(N,0));
	vector<vector<int>> sero(N,vector<int>(N,0));
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			cin>>wall[i][j];
		}
	}
	garo[0][1]=1;
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			if(wall[i][j]==0){
				if(i-1>=0&&j>=0&&wall[i-1][j]==0){
					sero[i][j]+=sero[i-1][j]+daeg[i-1][j];
				}
				if(i>=0&&j-1>=0&&wall[i][j-1]==0){
					garo[i][j]+=garo[i][j-1]+daeg[i][j-1];
				}
				if(i-1>=0&&j-1>=0&&wall[i-1][j-1]==0&&wall[i][j-1]==0&&wall[i-1][j]==0){
					daeg[i][j]+=garo[i-1][j-1]+daeg[i-1][j-1]+sero[i-1][j-1];
				}
			}
		}
	}
	cout<<daeg[N-1][N-1]+garo[N-1][N-1]+sero[N-1][N-1];
}
