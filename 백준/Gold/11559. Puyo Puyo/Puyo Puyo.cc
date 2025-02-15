#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
vector<vector<char>> M(6,vector<char>(12,'.'));
bool checked[6][12];
void print(){
	for(int j=11;j>=0;--j){
		for(int i=0;i<6;++i){
			cout<<M[i][j];
		}
		cout<<endl;
	}
}
int x[4]={0,0,1,-1};
int y[4]={1,-1,0,0};
bool in(int x, int y){
	return 0<=x&&x<6&&0<=y&&y<12;
}
queue<pair<int,int>> Q;
int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	for(int j=11;j>=0;--j){
		for(int i=0;i<6;++i){
			char s;
			cin>>s;
			M[i][j]=s;
		}
	}
	int chain=0;
	while(1){
		bool isboom=false;
		memset(checked,0,sizeof(checked));
		for(int i=0;i<6;++i){
			for(int j=0;j<12;++j){
				if(checked[i][j]) continue;
				if(M[i][j]=='.'){
					checked[i][j]=true;
					continue;
				}
				vector<pair<int,int>> C;
				Q.push({i,j});
				C.push_back({i,j});
				checked[i][j]=true;
				while(!Q.empty()){
					auto P=Q.front();
					Q.pop();
					for(int k=0;k<4;++k){
						int xk=P.first+x[k];
						int yk=P.second+y[k];
						if(in(xk,yk)&&!checked[xk][yk]&&M[xk][yk]==M[i][j]){
							Q.push({xk,yk});
							checked[xk][yk]=true;
							C.push_back({xk,yk});
						}
					}
				}
				if(C.size()>=4){
					isboom=true;
					for(auto e:C){
						M[e.first][e.second]='.';
					}
				}
			}
		}
		if(isboom) chain++;
		else break;
		for(int i=0;i<6;++i){
			vector<char> L;
			for(int j=0;j<12;++j){
				if(M[i][j]!='.') L.push_back(M[i][j]);
			}
			M[i].assign(12,'.');
			for(int j=0;j<L.size();++j){
				M[i][j]=L[j];
			}
		}
	}
	cout<<chain;
}