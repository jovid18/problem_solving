#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;
int T, N;
string S;
vector<string> O,R;
bool G[151][2][2];
int C[151];
bool finish;
void DFS(int count, int now){
	if(finish) return;
	if(count==N){
		for(int i=0;i<N;++i){
			cout<<C[i];
		}
		finish=true;
		cout<<'\n';
		return;
	}
	if(count==0){
		if(G[count][0][0]){
			C[count]=0;
			DFS(count+1,0);
		}
		if(G[count][0][1]){
			C[count]=0;
			DFS(count+1,1);
		}
		if(G[count][1][0]){
			C[count]=1;
			DFS(count+1,0);
		}
		if(G[count][1][1]){
			C[count]=1;
			DFS(count+1,1);
		}
	}else{
		if(G[count][now][0]){
			C[count]=now;
			DFS(count+1,0);
		}
		if(G[count][now][1]){
			C[count]=now;
			DFS(count+1,1);
		}
	}
}
int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>T;
	while(T--){
		cin>>N;
		O.clear();
		R.clear();
		memset(C,-1,sizeof(C));
		memset(G,0,sizeof(G));
		finish=false;
		for(int i=0;i<N;++i){
			cin>>S;
			O.push_back(S);
			reverse(S.begin(),S.end());
			R.push_back(S);
		}
		for(int i=0;i<N-1;++i){
			if(O[i]<O[i+1]) G[i][0][0]=true;
			if(O[i]<R[i+1]) G[i][0][1]=true;
			if(R[i]<O[i+1]) G[i][1][0]=true;
			if(R[i]<R[i+1]) G[i][1][1]=true;
		}
		G[N-1][0][0]=true;
		G[N-1][0][1]=true;
		G[N-1][1][0]=true;
		G[N-1][1][1]=true;
		DFS(0,0);
	}
}