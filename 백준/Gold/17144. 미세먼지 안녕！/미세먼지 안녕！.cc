#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main(){
	int R,C,T;
	cin>>R>>C>>T;
	vector<vector<int>> dust(R,vector<int> (C,0));
	for(int i=0;i<R;++i){
		for(int j=0;j<C;++j){
			cin>>dust[i][j];
		}
	}
	int cleaner=0;
	for(int i=0;i<R;++i){
		if(dust[i][0]==-1){
			cleaner=i;
			break;
		}
	}
	for(int m=0;m<T;++m){
		vector<vector<int>> copy(R,vector<int> (C,0));
		for(int j=0;j<R;++j){
			for(int k=0;k<C;++k){
				int count=0;
				if(dust[j][k]>0){
					if(j>=1&&dust[j-1][k]!=-1){
						count++;
						copy[j-1][k]+=dust[j][k]/5;
					}
					if(k>=1&&dust[j][k-1]!=-1){
						count++;
						copy[j][k-1]+=dust[j][k]/5;
					}
					if(j<(R-1)&&dust[j+1][k]!=-1){
						count++;
						copy[j+1][k]+=dust[j][k]/5;
					}
					if(k<(C-1)&&dust[j][k+1]!=-1){
						count++;
						copy[j][k+1]+=dust[j][k]/5;
					}
					copy[j][k]-=count*(dust[j][k]/5);
				}
			}
		}
		for(int j=0;j<R;++j){
			for(int k=0;k<C;++k){
				dust[j][k]+=copy[j][k];
			}
		}
		for(int i=cleaner-1;i>=1;--i){
			dust[i][0]=dust[i-1][0];
		}
		for(int i=0;i<=C-2;++i){
			dust[0][i]=dust[0][i+1];
		}
		for(int i=0;i<cleaner;++i){
			dust[i][C-1]=dust[i+1][C-1];
		}
		for(int i=C-1;i>=2;--i){
			dust[cleaner][i]=dust[cleaner][i-1];
		}
		dust[cleaner][1]=0;
		for(int i=cleaner+2;i<=R-2;++i){
			dust[i][0]=dust[i+1][0];
		}
		for(int i=0;i<=C-2;++i){
			dust[R-1][i]=dust[R-1][i+1];
		}
		for(int i=R-1;i>=cleaner+2;--i){
			dust[i][C-1]=dust[i-1][C-1];
		}
		for(int i=C-1;i>=2;--i){
			dust[cleaner+1][i]=dust[cleaner+1][i-1];
		}
		dust[cleaner+1][1]=0;
	}
	int dustsum=0;
	for(auto e:dust){
		for(auto f:e){
			if(f>0){
				dustsum+=f;
			}
		}
	}
	cout<<dustsum;
}
