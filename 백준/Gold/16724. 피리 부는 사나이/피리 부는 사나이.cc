#include <iostream>
#include <vector>
using namespace std;
int N,M;
struct unionfind{
	vector<vector<pair<int,int>>> par;
	vector<vector<int>> siz;
	unionfind(int n,int m): par(n,vector<pair<int,int>> (m,{-1,-1})),siz(n,vector<int> (m,0)) {}
	pair<int,int> root(int x,int y){
		if(par[x][y]==make_pair(-1,-1)){
			return {x,y};
		}else{
			return par[x][y]=root(par[x][y].first,par[x][y].second);
		}
	}
	bool issame(int x1,int y1,int x2, int y2){
		return root(x1,y1)==root(x2,y2);
	}
	bool unite(int x1,int y1,int x2, int y2){
		auto a=root(x1,y1);
		auto b=root(x2,y2);
		x1=a.first;
		y1=a.second;
		x2=b.first;
		y2=b.second;
		if(a==b){
			return false;
		}
		if(siz[x1][y1]<siz[x2][y2]) {
			swap(x1,y1);
			swap(x2,y2);
		}
		par[x2][y2]={x1,y1};
		siz[x1][y1]+=siz[x2][y2];
		return true;
	}
};
int main(){
	cin>>N>>M;
	unionfind uf(N,M);
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			char c;
			cin>>c;
			if(c=='R'){
				uf.unite(i,j,i,j+1);
			}else if(c=='U'){
				uf.unite(i,j,i-1,j);
			}else if(c=='L'){
				uf.unite(i,j,i,j-1);
			}else{
				uf.unite(i,j,i+1,j);
			}
		}
	}
	int count=0;
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			if(uf.par[i][j]==make_pair(-1,-1)) count++;
		}
	}
	cout<<count;
}