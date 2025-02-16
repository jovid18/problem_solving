#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N,M,S;
vector<int> A;
vector<int> B;
vector<int> Asum;
vector<int> Bsum;
void dfs(int count, int sum,vector<int> v,vector<int> &s){
	if(count==v.size()){
		s.push_back(sum);
		return;
	}
	dfs(count+1,sum,v,s);
	dfs(count+1,sum+v[count],v,s);
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>S;
	M=N/2;
	N=N-M;
	A.resize(N);
	B.resize(M);
	for(int i=0;i<N;++i){
		cin>>A[i];
	}
	for(int i=0;i<M;++i){
		cin>>B[i];
	}
	dfs(0,0,A,Asum);
	dfs(0,0,B,Bsum);
	sort(Asum.begin(),Asum.end());
	sort(Bsum.begin(),Bsum.end());
	long long count=0;
	for(auto iter=Asum.begin();iter!=Asum.end();iter++){
		if(*iter==0){
			Asum.erase(iter);
			break;
		}
	}
	for(auto iter=Bsum.begin();iter!=Bsum.end();iter++){
		if(*iter==0){
			Bsum.erase(iter);
			break;
		}
	}
	auto iter1=upper_bound(Asum.begin(),Asum.end(),S);
	auto iter2=lower_bound(Asum.begin(),Asum.end(),S);
	count+=(iter1-iter2);
	auto iter3=upper_bound(Bsum.begin(),Bsum.end(),S);
	auto iter4=lower_bound(Bsum.begin(),Bsum.end(),S);
	count+=(iter3-iter4);
	for(int i=0;i<Asum.size();++i){
		auto iter1=upper_bound(Bsum.begin(),Bsum.end(),S-Asum[i]);
		auto iter2=lower_bound(Bsum.begin(),Bsum.end(),S-Asum[i]);
		count+=(iter1-iter2);
	}
	cout<<count;
}