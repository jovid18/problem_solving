#include <iostream>
#include <vector>
using namespace std;

int N,M;
vector<vector<char>> B;
int minscore=11;
pair<int,int> r,b,h;
int x[4]={1,-1,0,0};
int y[4]={0,0,1,-1};
struct infor{
	int check;
	vector<vector<char>> Bnow;
	pair<int,int>rnow;
	pair<int,int>bnow;	
};
infor command(int i,vector<vector<char>> B,pair<int,int> r,pair<int,int>b){
		auto Bcopy=B;
		auto rcopy=r;
		auto bcopy=b;
		if(i==0){
			if(r.first<b.first){
				int bx=b.first+x[i];
				int by=b.second+y[i];
				while(Bcopy[bx][by]=='.'){
					bx+=x[i];
					by+=y[i];
				}
				bx-=x[i];
				by-=y[i];
				if(Bcopy[bx+x[i]][by+y[i]]=='O'){
					bcopy={0,0};
					Bcopy[b.first][b.second]='.';
				}else{
					Bcopy[b.first][b.second]='.';
					Bcopy[bx][by]='B';
					bcopy={bx,by};
				}
				int rx=r.first+x[i];
				int ry=r.second+y[i];
				while(Bcopy[rx][ry]=='.'){
					rx+=x[i];
					ry+=y[i];
				}
				rx-=x[i];
				ry-=y[i];
				if(Bcopy[rx+x[i]][ry+y[i]]=='O'){
					rcopy={0,0};
					Bcopy[r.first][r.second]='.';
				}else{
					Bcopy[r.first][r.second]='.';
					Bcopy[rx][ry]='R';
					rcopy={rx,ry};
				}
			}else{
				int rx=r.first+x[i];
				int ry=r.second+y[i];
				while(Bcopy[rx][ry]=='.'){
					rx+=x[i];
					ry+=y[i];
				}
				rx-=x[i];
				ry-=y[i];
				if(Bcopy[rx+x[i]][ry+y[i]]=='O'){
					rcopy={0,0};
					Bcopy[r.first][r.second]='.';
				}else{
					Bcopy[r.first][r.second]='.';
					Bcopy[rx][ry]='R';
					rcopy={rx,ry};
				}
				int bx=b.first+x[i];
				int by=b.second+y[i];
				while(Bcopy[bx][by]=='.'){
					bx+=x[i];
					by+=y[i];
				}
				bx-=x[i];
				by-=y[i];
				if(Bcopy[bx+x[i]][by+y[i]]=='O'){
					bcopy={0,0};
					Bcopy[b.first][b.second]='.';
				}else{
					Bcopy[b.first][b.second]='.';
					Bcopy[bx][by]='B';
					bcopy={bx,by};
				}
			}
		}else if(i==1){
			if(r.first>b.first){
				int bx=b.first+x[i];
				int by=b.second+y[i];
				while(Bcopy[bx][by]=='.'){
					bx+=x[i];
					by+=y[i];
				}
				bx-=x[i];
				by-=y[i];
				if(Bcopy[bx+x[i]][by+y[i]]=='O'){
					bcopy={0,0};
					Bcopy[b.first][b.second]='.';
				}else{
					Bcopy[b.first][b.second]='.';
					Bcopy[bx][by]='B';
					bcopy={bx,by};
				}
				int rx=r.first+x[i];
				int ry=r.second+y[i];
				while(Bcopy[rx][ry]=='.'){
					rx+=x[i];
					ry+=y[i];
				}
				rx-=x[i];
				ry-=y[i];
				if(Bcopy[rx+x[i]][ry+y[i]]=='O'){
					rcopy={0,0};
					Bcopy[r.first][r.second]='.';
				}else{
					Bcopy[r.first][r.second]='.';
					Bcopy[rx][ry]='R';
					rcopy={rx,ry};
				}
			}else{
				int rx=r.first+x[i];
				int ry=r.second+y[i];
				while(Bcopy[rx][ry]=='.'){
					rx+=x[i];
					ry+=y[i];
				}
				rx-=x[i];
				ry-=y[i];
				if(Bcopy[rx+x[i]][ry+y[i]]=='O'){
					rcopy={0,0};
					Bcopy[r.first][r.second]='.';
				}else{
					Bcopy[r.first][r.second]='.';
					Bcopy[rx][ry]='R';
					rcopy={rx,ry};
				}
				int bx=b.first+x[i];
				int by=b.second+y[i];
				while(Bcopy[bx][by]=='.'){
					bx+=x[i];
					by+=y[i];
				}
				bx-=x[i];
				by-=y[i];
				if(Bcopy[bx+x[i]][by+y[i]]=='O'){
					bcopy={0,0};
					Bcopy[b.first][b.second]='.';
				}else{
					Bcopy[b.first][b.second]='.';
					Bcopy[bx][by]='B';
					bcopy={bx,by};
				}
			}
		}else if(i==2){
			if(r.second<b.second){
				int bx=b.first+x[i];
				int by=b.second+y[i];
				while(Bcopy[bx][by]=='.'){
					bx+=x[i];
					by+=y[i];
				}
				bx-=x[i];
				by-=y[i];
				if(Bcopy[bx+x[i]][by+y[i]]=='O'){
					bcopy={0,0};
					Bcopy[b.first][b.second]='.';
				}else{
					Bcopy[b.first][b.second]='.';
					Bcopy[bx][by]='B';
					bcopy={bx,by};
				}
				int rx=r.first+x[i];
				int ry=r.second+y[i];
				while(Bcopy[rx][ry]=='.'){
					rx+=x[i];
					ry+=y[i];
				}
				rx-=x[i];
				ry-=y[i];
				if(Bcopy[rx+x[i]][ry+y[i]]=='O'){
					rcopy={0,0};
					Bcopy[r.first][r.second]='.';
				}else{
					Bcopy[r.first][r.second]='.';
					Bcopy[rx][ry]='R';
					rcopy={rx,ry};
				}
			}else{
				int rx=r.first+x[i];
				int ry=r.second+y[i];
				while(Bcopy[rx][ry]=='.'){
					rx+=x[i];
					ry+=y[i];
				}
				rx-=x[i];
				ry-=y[i];
				if(Bcopy[rx+x[i]][ry+y[i]]=='O'){
					rcopy={0,0};
					Bcopy[r.first][r.second]='.';
				}else{
					Bcopy[r.first][r.second]='.';
					Bcopy[rx][ry]='R';
					rcopy={rx,ry};
				}
				int bx=b.first+x[i];
				int by=b.second+y[i];
				while(Bcopy[bx][by]=='.'){
					bx+=x[i];
					by+=y[i];
				}
				bx-=x[i];
				by-=y[i];
				if(Bcopy[bx+x[i]][by+y[i]]=='O'){
					bcopy={0,0};
					Bcopy[b.first][b.second]='.';
				}else{
					Bcopy[b.first][b.second]='.';
					Bcopy[bx][by]='B';
					bcopy={bx,by};
				}
			}
		}else{
			if(r.second>b.second){
				int bx=b.first+x[i];
				int by=b.second+y[i];
				while(Bcopy[bx][by]=='.'){
					bx+=x[i];
					by+=y[i];
				}
				bx-=x[i];
				by-=y[i];
				if(Bcopy[bx+x[i]][by+y[i]]=='O'){
					bcopy={0,0};
					Bcopy[b.first][b.second]='.';
				}else{
					Bcopy[b.first][b.second]='.';
					Bcopy[bx][by]='B';
					bcopy={bx,by};
				}
				int rx=r.first+x[i];
				int ry=r.second+y[i];
				while(Bcopy[rx][ry]=='.'){
					rx+=x[i];
					ry+=y[i];
				}
				rx-=x[i];
				ry-=y[i];
				if(Bcopy[rx+x[i]][ry+y[i]]=='O'){
					rcopy={0,0};
					Bcopy[r.first][r.second]='.';
				}else{
					Bcopy[r.first][r.second]='.';
					Bcopy[rx][ry]='R';
					rcopy={rx,ry};
				}
			}else{
				int rx=r.first+x[i];
				int ry=r.second+y[i];
				while(Bcopy[rx][ry]=='.'){
					rx+=x[i];
					ry+=y[i];
				}
				rx-=x[i];
				ry-=y[i];
				if(Bcopy[rx+x[i]][ry+y[i]]=='O'){
					rcopy={0,0};
					Bcopy[r.first][r.second]='.';
				}else{
					Bcopy[r.first][r.second]='.';
					Bcopy[rx][ry]='R';
					rcopy={rx,ry};
				}
				int bx=b.first+x[i];
				int by=b.second+y[i];
				while(Bcopy[bx][by]=='.'){
					bx+=x[i];
					by+=y[i];
				}
				bx-=x[i];
				by-=y[i];
				if(Bcopy[bx+x[i]][by+y[i]]=='O'){
					bcopy={0,0};
					Bcopy[b.first][b.second]='.';
				}else{
					Bcopy[b.first][b.second]='.';
					Bcopy[bx][by]='B';
					bcopy={bx,by};
				}
			}
		}
	infor s;
	if(bcopy.first==0){
		s={-1,Bcopy,rcopy,bcopy};	
	}else if(rcopy.first==0){
		s={0,Bcopy,rcopy,bcopy};
	}else if(Bcopy==B){
		s={1,Bcopy,rcopy,bcopy};
	}else{
		s={2,Bcopy,rcopy,bcopy};
	}
	return s;
};
void dfs(int n,vector<vector<char>> B,pair<int,int> r,pair<int,int>b){
	if(n==11) return;
	for(int i=0;i<4;++i){
		auto info=command(i,B,r,b);
		if(info.check==0){
			minscore=min(minscore,n);
		}else if(info.check==2){
			dfs(n+1,info.Bnow,info.rnow,info.bnow);
		}
	}
}
int main(){
	cin>>N>>M;
	B.assign(N,vector<char> (M,','));
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			cin>>B[i][j];
			if(B[i][j]=='R') r={i,j};
			if(B[i][j]=='B') b={i,j};
			if(B[i][j]=='0') h={i,j};
		}
	}
	dfs(1,B,r,b);
	if(minscore==11){
		cout<<-1;
	}else{
		cout<<minscore;
	}
}