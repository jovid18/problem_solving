#include <iostream>
#include <vector>
using namespace std;
int X,N,P,INF=1e9;
vector<vector<int>> T,DP,DP1,DP2,DP3;
bool edge(int a, int b, int c, int d){
	return (T[a][b]+T[c][d]<=P);
}
void chmin(int &a, int b){
	if(a>b) a=b;
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>X;
	while(X--){
		cin>>N>>P;
		T.assign(2,vector<int> (N,0));
		DP.assign(N,vector<int> (3,INF));
		DP1.assign(N,vector<int> (3,INF));
		DP2.assign(N,vector<int> (3,INF));
		DP3.assign(N,vector<int> (3,INF));
		for(int i=0;i<2;++i){
			for(int j=0;j<N;++j){
				cin>>T[i][j];
			}
		}
		for(int k=0;k<N;++k){
			if(k==0){
				DP[k][0]=2;
				if(edge(0,k,1,k)) DP[k][0]=1;
				DP[k][1]=1;
				DP[k][2]=1;
			}else{
				if(k==1){
					if(edge(0,k-1,0,k)&&edge(1,k-1,1,k)) DP[k][0]=2;
				}
				chmin(DP[k][0],DP[k-1][0]+2);
				chmin(DP[k][1],DP[k-1][0]+1);
				chmin(DP[k][2],DP[k-1][0]+1);
				if(edge(0,k,1,k)) chmin(DP[k][0],DP[k-1][0]+1);
				if(k>=2&&edge(0,k-1,0,k)&&edge(1,k-1,1,k)) 
				chmin(DP[k][0],DP[k-2][0]+2);
				if(edge(0,k-1,0,k)) chmin(DP[k][0],DP[k-1][2]+2);
				if(edge(1,k-1,1,k)) chmin(DP[k][0],DP[k-1][1]+2);
				if(edge(0,k-1,0,k)) chmin(DP[k][1],DP[k-1][2]+1);
				if(edge(1,k-1,1,k)) chmin(DP[k][2],DP[k-1][1]+1);
			}
		}
		if(N!=1&&edge(0,0,0,N-1)){
			for(int k=0;k<N;++k){
				if(k==0){
					DP1[k][2]=2;
				}else{
					if(k==1){
						DP1[k][0]=4;
						DP1[k][1]=3;
						DP1[k][2]=3;
						if(edge(0,k,1,k)) chmin(DP1[k][0],3);
						if(edge(1,k-1,1,k)) chmin(DP1[k][0],3);
						if(edge(1,k-1,1,k)) chmin(DP1[k][2],2);
						continue;
					}
					chmin(DP1[k][0],DP1[k-1][0]+2);
					chmin(DP1[k][1],DP1[k-1][0]+1);
					chmin(DP1[k][2],DP1[k-1][0]+1);
					if(edge(0,k,1,k)) chmin(DP1[k][0],DP1[k-1][0]+1);
					if(k>=3&&edge(0,k-1,0,k)&&edge(1,k-1,1,k)) 
					chmin(DP1[k][0],DP1[k-2][0]+2);
					if(edge(0,k-1,0,k)) chmin(DP1[k][0],DP1[k-1][2]+2);
					if(edge(1,k-1,1,k)) chmin(DP1[k][0],DP1[k-1][1]+2);
					if(edge(0,k-1,0,k)) chmin(DP1[k][1],DP1[k-1][2]+1);
					if(edge(1,k-1,1,k)) chmin(DP1[k][2],DP1[k-1][1]+1);
				}
			}
		}
		if(N!=1&&edge(1,0,1,N-1)){
			for(int k=0;k<N;++k){
				if(k==0){
					DP2[k][1]=2;
				}else{
					if(k==1){
						DP2[k][0]=4;
						DP2[k][1]=3;
						DP2[k][2]=3;
						if(edge(0,k,1,k)) chmin(DP2[k][0],3);
						if(edge(0,k-1,0,k)) chmin(DP2[k][0],3);
						if(edge(0,k-1,0,k)) chmin(DP2[k][1],2);
						continue;
					}
					chmin(DP2[k][0],DP2[k-1][0]+2);
					chmin(DP2[k][1],DP2[k-1][0]+1);
					chmin(DP2[k][2],DP2[k-1][0]+1);
					if(edge(0,k,1,k)) chmin(DP2[k][0],DP2[k-1][0]+1);
					if(k>=3&&edge(0,k-1,0,k)&&edge(1,k-1,1,k)) 
					chmin(DP2[k][0],DP2[k-2][0]+2);
					if(edge(0,k-1,0,k)) chmin(DP2[k][0],DP2[k-1][2]+2);
					if(edge(1,k-1,1,k)) chmin(DP2[k][0],DP2[k-1][1]+2);
					if(edge(0,k-1,0,k)) chmin(DP2[k][1],DP2[k-1][2]+1);
					if(edge(1,k-1,1,k)) chmin(DP2[k][2],DP2[k-1][1]+1);
				}
			}
		}
		if(N!=1&&edge(0,0,0,N-1)&&edge(1,0,1,N-1)){
			for(int k=1;k<N-1;++k){
				if(k==1){
					DP3[k][0]=4;
					DP3[k][1]=3;
					DP3[k][2]=3;
					if(edge(0,k,1,k)) DP3[k][0]=3;
				}else{
					if(k==2){
						if(edge(0,k-1,0,k)&&edge(1,k-1,1,k)) DP3[k][0]=4;
					}
					chmin(DP3[k][0],DP3[k-1][0]+2);
					chmin(DP3[k][1],DP3[k-1][0]+1);
					chmin(DP3[k][2],DP3[k-1][0]+1);
					if(edge(0,k,1,k)) chmin(DP3[k][0],DP3[k-1][0]+1);
					if(k>=3&&edge(0,k-1,0,k)&&edge(1,k-1,1,k)) 
					chmin(DP3[k][0],DP3[k-2][0]+2);
					if(edge(0,k-1,0,k)) chmin(DP3[k][0],DP3[k-1][2]+2);
					if(edge(1,k-1,1,k)) chmin(DP3[k][0],DP3[k-1][1]+2);
					if(edge(0,k-1,0,k)) chmin(DP3[k][1],DP3[k-1][2]+1);
					if(edge(1,k-1,1,k)) chmin(DP3[k][2],DP3[k-1][1]+1);
				}
			}
		}
		int ans=INF;
		chmin(ans,DP[N-1][0]);
		if(N!=1){
			chmin(ans,DP1[N-1][2]);
			chmin(ans,DP2[N-1][1]);
			chmin(ans,DP3[N-2][0]);
		}
		cout<<ans<<'\n';
	}
}
