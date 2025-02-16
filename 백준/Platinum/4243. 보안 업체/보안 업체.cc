#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int N,M,T;
using ll=long long;
vector<ll> D;
const ll INF=1e15;
ll DP[101][101][2];
ll find(int l, int r, int s){
	ll &ret=DP[l][r][s];
	if(ret!=-1){
		return ret;
	}
	if(l==1&&r==N){
		ret=0;
		return ret;
	}
	ll left=INF,right=INF;
	ll rem=N-r+l-1;
	if(l!=1){
		if(!s){
			left=min(left,find(l-1,r,0)+rem*(D[l]-D[l-1]));
		}else{
			left=min(left,find(l-1,r,0)+rem*(D[r]-D[l-1]));
		}
	}
	if(r!=N){
		if(!s){
			right=min(right,find(l,r+1,1)+rem*(D[r+1]-D[l]));
		}else{
			right=min(right,find(l,r+1,1)+rem*(D[r+1]-D[r]));
		}
	}
	ret=min(right,left);
	return ret;
}
int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>T;
	while(T--){
		int a;
		cin>>N>>a;
		D.resize(N+1);
		D[1]=0;
		for(int i=2;i<=N;++i){
			ll d;
			cin>>d;
			D[i]=d+D[i-1];
		}
		memset(DP,-1,sizeof(DP));
		cout<<find(a,a,0)<<'\n';
	}
}