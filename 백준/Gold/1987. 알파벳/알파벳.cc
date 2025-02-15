#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int R,C;
vector<vector<char>> board;
vector<bool> checked(26,false);
stack<pair<int,int>> process;

int num(char a){
	return a-65;
}
int xc[4]={1,-1,0,0};
int yc[4]={0,0,-1,1};
int MAX=1;
void DFS(int count,int x, int y){
	if(MAX<count){
		MAX=count;
	}
	checked[num(board[x][y])]=true;
	for(int n=0;n<4;++n){
		int xn=x+xc[n];
		int yn=y+yc[n];
		if(0<=xn&&xn<R&&0<=yn&&yn<C&&!checked[num(board[xn][yn])]){
			checked[num(board[xn][yn])]=true;
			DFS(count+1,xn,yn);
			checked[num(board[xn][yn])]=false;
		}
	}
	
}
int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>R>>C;
	board.resize(R);
	for(int i=0;i<R;++i){
		board[i].resize(C);
		for(int j=0;j<C;++j){
			cin>>board[i][j];
		}
	}
	DFS(1,0,0);
	cout<<MAX;
}