#include <iostream>
#include <vector>
using namespace std;
int A[100000]={0};
vector<pair<int,int>> T(400000,{0,0});
int N,M;
pair<int,int> init(int s,int f,int n){
	if(s==f) return T[n]={A[s],A[s]};
	int m=(s+f)/2;
	auto p1=init(s,m,2*n);
	auto p2=init(m+1,f,2*n+1);
	return T[n]={min(p1.first,p2.first),max(p1.second,p2.second)};
}
pair<int,int> query(int s,int f,int n,int l,int r){
	if(f<l||r<s) return{1000000001,0};
	if(l<=s&&f<=r) return T[n];
	int m=(s+f)/2;
	auto p1=query(s,m,2*n,l,r);
	auto p2=query(m+1,f,2*n+1,l,r);
	return {min(p1.first,p2.first),max(p1.second,p2.second)};
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>M;
	for(int i=0;i<N;++i){
		cin>>A[i];
	}
	init(0,N-1,1);
	for(int i=0;i<M;++i){
		int a,b;
		cin>>a>>b;
		auto p=query(0,N-1,1,a-1,b-1);
		cout<<p.first<<" "<<p.second<<'\n';
	}
}
