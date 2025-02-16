#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
using ll=long long;
int N,M;
int S[3][2];
int ans=0;
void solve(int count, int tot,int lastwork){
	if(count==N){
		if(tot>=M) ans++;
		return ;
	}
	for(int i=0;i<3;++i){
		for(int j=0;j<2;++j){
			if(i==lastwork){
				solve(count+1,tot+S[i][j]/2,i);
			}else{
				solve(count+1,tot+S[i][j],i);
			}
		}
	}
}
int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>N>>M;
	for(int j=0;j<2;++j){
		for(int i=0;i<3;++i){
			cin>>S[i][j];
		}
	}
	solve(0,0,-1);
	cout<<ans;
}