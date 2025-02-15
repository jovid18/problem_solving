#include<iostream>
#include <vector>
using namespace std;
vector<int> A(100000,0);
vector<pair<int,int>> T(4000000,{0,0});
long long area=0;
pair<int,int> init(int s,int f,int n){
	if(s==f) return T[n]={A[s],s};
	int m=(s+f)/2;
	auto pair1=init(s,m,2*n);
	auto pair2=init(m+1,f,2*n+1);
	if(pair1.first<=pair2.first){
		return T[n]=pair1;
	}else{
		return T[n]=pair2;
	}
}
pair<int,int> find(int s,int f,int n,int l,int r){
	if(f<l||r<s) return {1e9+1,1};
	if(l<=s&&f<=r) return T[n];
	int m=(s+f)/2;
	auto pair1=find(s,m,2*n,l,r);
	auto pair2=find(m+1,f,2*n+1,l,r);
	if(pair1.first<=pair2.first){
		return pair1;
	}else{
		return pair2;
	}
}
void solve(int s,int f,int l,int r){
	if(l>r) return;
	if(l==r){
		area=max(area,(long long)A[l]);
		return;
	}
	auto P=find(s,f,1,l,r);
	area=max(area,(long long)(r-l+1)*P.first);
	if(r!=P.second) solve(s,f,P.second+1,r);
	if(l!=P.second) solve(s,f,l,P.second-1);
}
int main(){
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int N;
	cin>>N;
	for(int i=0;i<N;++i){
		cin>>A[i];
	}
	auto P=init(0,N-1,1);
	solve(0,N-1,0,N-1);
	cout<<area;
}