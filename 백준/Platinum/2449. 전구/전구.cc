#include <iostream>
#include <cstring>
using namespace std;
int C[200];
int DP[200][200];
int N,K;
int find(int s,int f){
	int &ret=DP[s][f];
	if(ret!=-1) return ret;
	if(s==f) return 0;
	if(f==s+1) return C[s]!=C[f];
	ret=1e9;
	for(int i=s;i<f;++i){
		ret=min(ret,find(s,i)+find(i+1,f)+(C[s]!=C[i+1]));
	}
	return ret;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>K;
	for(int i=0;i<N;++i){
		cin>>C[i];
	}
	memset(DP, -1, sizeof(DP));
	cout<<find(0,N-1);
}