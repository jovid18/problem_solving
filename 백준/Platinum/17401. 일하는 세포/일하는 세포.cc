#include <iostream>
#include <vector>
using namespace std;
using ll=long long;
using MATRIX=vector<vector<ll>>;
MATRIX matrix;
const ll MOD=1000000007;
int T,N,D;
vector<MATRIX> M;

MATRIX multiply(MATRIX &A,MATRIX &B){
	MATRIX C=A;
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			ll sum=0;
			for(int k=0;k<N;++k){
				sum+=A[i][k]*B[k][j]%MOD;
			}
			C[i][j]=sum%MOD;
		}
	}
	return C;
}

MATRIX  power(MATRIX &a,int b){
	if(b==1){
		return a;
	}
	if(b%2==0){
		MATRIX c=power(a,b/2);
		return multiply(c,c);
	}else{
		MATRIX c=power(a,(b-1)/2);
		c=multiply(c, c);
		return multiply(c,a);
	}
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>T>>N>>D;
	M.resize(T);
	for(int i=0;i<T;++i){
		M[i].assign(N,vector<ll>(N,0));
		int m;
		cin>>m;
		for(int j=0;j<m;++j){
			int a,b;
			ll c;
			cin>>a>>b>>c;
			M[i][a-1][b-1]=c;
		}
	}
	int cycle=D/T;
	int remain=D%T;
	MATRIX I(N,vector <ll>(N,0));
	for(int i=0;i<N;++i){
		I[i][i]=1;
	}
	if(cycle==0){
		for(int i=0;i<remain;++i){
			I=multiply(I,M[i]);
		}
	}else{
		for(int i=0;i<T;++i){
			I=multiply(I,M[i]);
		}
		I=power(I, cycle);
		for(int i=0;i<remain;++i){
			I=multiply(I,M[i]);
		}
	}
	for(auto e:I){
		for(auto f:e){
			cout<<f<<" ";
		}
		cout<<'\n';
	}
}
