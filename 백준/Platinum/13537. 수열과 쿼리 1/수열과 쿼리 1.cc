#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int A[100000];
vector<int> T[400000];
vector<int> init(int s, int f, int n){
	if(s==f){
		T[n].push_back(A[s]);
		return T[n];
	}
	int m=(s+f)/2;
	auto left=init(s,m,2*n);
	auto right=init(m+1,f,2*n+1);
	T[n].insert(T[n].end(),left.begin(),left.end());
	T[n].insert(T[n].end(),right.begin(),right.end());
	sort(T[n].begin(),T[n].end());
	return T[n];
}
int query(int s, int f, int n, int l, int r, int k){
	if(l>f||r<s) return 0;
	if(l<=s&&f<=r){
		int idx=upper_bound(T[n].begin(),T[n].end(),k)-T[n].begin();
		return T[n].size()-idx;
	} 
	int m=(s+f)/2;
	return query(s,m,2*n,l,r,k)+query(m+1,f,2*n+1,l,r,k);
}
int N,M;
int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>N;
	for(int i=0;i<N;++i){
		cin>>A[i];
	}
	init(0,N-1,1);
	cin>>M;
	int i,j,k;
	while(M--){
		cin>>i>>j>>k;
		cout<<query(0,N-1,1,i-1,j-1,k)<<'\n';
	}
	
}