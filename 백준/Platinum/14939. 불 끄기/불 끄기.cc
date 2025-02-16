#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<char>> B(10,vector<char> (10,'O'));
vector<vector<vector<char>>> DP(1024);
vector<int> C(1023,0);
vector<bool> D(1023,true);
int x[]={1,-1,0,0};
int y[]={0,0,1,-1};
void sw(vector<vector<char>> &B, int r, int c){
	if(B[r][c]=='O'){
		B[r][c]='#';
	}else{
		B[r][c]='O';
	}
	int rx,cy;
	for(int i=0;i<4;++i){
		rx=r+x[i];
		cy=c+y[i];
		if(0<=rx&&rx<10&&0<=cy&&cy<10){
			if(B[rx][cy]=='O'){
				B[rx][cy]='#';
			}else{
				B[rx][cy]='O';
			}
		}
	}
}
void first(vector<vector<vector<char>>> &DP){
	for(int i=0;i<1024;++i){
		for(int k=0;k<10;++k){
			if(i&(1<<k)){
				sw(DP[i],0,k);
				C[i]++;
			}
		}
	}
}
void remain(vector<vector<vector<char>>> &DP){
	for(int i=0;i<1024;++i){
		for(int k=1;k<10;++k){
			for(int j=0;j<10;++j){
				if(DP[i][k-1][j]=='O'){
					sw(DP[i],k,j);
					C[i]++;
				}
			}
		}
		for(int j=0;j<10;++j){
			if(DP[i][9][j]=='O'){
				D[i]=false;
				break;
			}
		}
	}
}
int main(){
	for(int i=0;i<10;++i){
		for(int j=0;j<10;++j){
			cin>>B[i][j];
		}
	}
	for(int i=0;i<1024;++i){
		DP[i]=B;
	}
	first(DP);
	remain(DP);
	int count=101;
	for(int i=0;i<1024;++i){
		if(!D[i]) continue;
		count=min(count,C[i]);
	}
	if(count==101){
		cout<<-1;
	}else{
		cout<<count;
	}
}
