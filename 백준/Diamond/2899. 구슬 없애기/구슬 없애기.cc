#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int N,K,INF=1e9;
int DP[100][100][5];
vector<int> A;
int sol(int l,int r, int c){
	if(l>r) return 0;
	if(l==r) return K-c-1;
	int &ret=DP[l][r][c];
	if(ret!=-1) return ret;
	ret=INF;
	if(c<K-1) ret=sol(l,r,c+1)+1;
	if(c==K-1) ret=sol(l+1,r,0);
	for(int x=l+1;x<=r;++x){
		if(A[l]==A[x])
		ret=min(ret,sol(l+1,x-1,0)+sol(x,r,min(c+1,K-1)));
	}
	return ret;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>K;
	A.resize(N);
	for(int i=0;i<N;++i){
		cin>>A[i];
	}
	memset(DP,-1,sizeof(DP)),
	cout<<sol(0,N-1,0);
}