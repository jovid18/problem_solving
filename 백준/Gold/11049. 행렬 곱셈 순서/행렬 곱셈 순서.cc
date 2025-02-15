#include <iostream>
#include <vector>
#include <climits>
using namespace std;
long long INF=LLONG_MAX;
int N;
vector<int> p;
int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>N;
	p.resize(N+1);
	for(int i=0;i<N;++i){
		cin>>p[i]>>p[i+1];
	}
	vector<vector<long long>> m(N+1,vector<long long> (N+1,0));
	for(int i=1;i<=N;++i){
		m[i][i]=0;
	}
	for(int l=2;l<=N;++l){
		for(int i=1;i<=N-l+1;++i){
			int j=i+l-1;
			m[i][j]=INF;
			for(int k=i;k<=j-1;++k){
				long long q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
				if(q<m[i][j]){
					m[i][j]=q;
				}
			}
		}
	}
	cout<<m[1][N];
	
	
}