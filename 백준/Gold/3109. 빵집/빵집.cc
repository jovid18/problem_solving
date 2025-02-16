#include <iostream>
#include <vector>
using namespace std;
int R,C;
char M[10000][500];
int r[3]={-1,0,1};
int c[3]={1,1,1};
bool in(int x,int y){
	if(0<=x&&x<R&&0<=y&&y<C) return true;
	else return false;
}
bool finish;
int cnt;
void dfs(int x,int y){
	if(finish) return;
	M[x][y]='x';
	if(y==C-1){
		cnt++;
		finish=true;
		return;
	}
	for(int i=0;i<3;++i){
		int xi=x+r[i];
		int yi=y+c[i];
		if(!in(xi,yi)) continue;
		if(M[xi][yi]=='.'){
			dfs(xi,yi);
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>R>>C;
	for(int i=0;i<R;++i){
		for(int j=0;j<C;++j){
			cin>>M[i][j];
		}
	}
	for(int i=0;i<R;++i){
		finish=false;
		if(M[i][0]=='x') continue;
		dfs(i,0);
	}
	cout<<cnt;
}
