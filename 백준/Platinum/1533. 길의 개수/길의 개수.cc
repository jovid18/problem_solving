#include <iostream>
#include <vector>
using namespace std;
using ll= long long;
vector<vector<ll>> G,R;
const int MOD=1000003;
vector<vector<ll>> multiply(vector<vector<ll>> A,vector<vector<ll>> B){
	auto C=A;
	int n=A.size();
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			ll sum=0;
			for(int k=0;k<n;++k){
				sum+=A[i][k]*B[k][j]%MOD;
			}
			C[i][j]=sum%MOD;
		}
	}
	return C;
}
vector<vector<ll>> power(vector<vector<ll>> &a, int b){
	if(b==1){
		return a;
	}
	if(b%2==0){
		vector<vector<ll>> c=power(a,b/2);
		return multiply(c,c);
	}else{
		vector<vector<ll>> c=power(a,(b-1)/2);
		return multiply(multiply(c,c),a);
	}
}
vector<vector<char>> C;
int N,S,E,T;
int main(){
	cin>>N>>S>>E>>T;
	S--;
	E--;
	C.assign(N,vector<char> (N,'0'));
	G.assign(N,vector<ll> (N,0));
	for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
        	cin>>C[i][j];
        	G[i][j]=C[i][j]-'0';
        }
    }
	R.assign(5*N,vector<ll> (5*N,0));
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			if(G[i][j]==0) continue;
			R[5*i][5*j+G[i][j]-1]=1;
		}
	}
	for(int i=0;i<5*N;++i){
		for(int j=0;j<5*N;++j){
			if(i==j+1&&i%5!=0){
				R[i][j]=1;
			}
		}
	}
	R=power(R, T);	
	cout<<R[5*S][5*E];
}
