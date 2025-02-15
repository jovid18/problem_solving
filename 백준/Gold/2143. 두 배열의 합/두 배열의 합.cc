#include <iostream>
#include <vector>
#include <algorithm>;
using namespace std;
long long T;
int N,M;
long long A[1001]={0};
long long B[1001]={0};
vector<long long> Asum;
vector<long long> Bsum;
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>T>>N;
	for(int i=1;i<=N;++i){
		cin>>A[i];
		A[i]+=A[i-1];
	}
	cin>>M;
	for(int i=1;i<=M;++i){
		cin>>B[i];
		B[i]+=B[i-1];
	}
	for(int i=1;i<=N;++i){
		for(int j=i;j<=N;++j){
			Asum.push_back(A[j]-A[i-1]);
		}
	}
	for(int i=1;i<=M;++i){
		for(int j=i;j<=M;++j){
			Bsum.push_back(B[j]-B[i-1]);
		}
	}
	sort(Asum.begin(),Asum.end());
	sort(Bsum.begin(),Bsum.end());
	long long count=0;
	for(int i=0;i<Asum.size();++i){
		long long S=T-Asum[i];
		count+=upper_bound(Bsum.begin(),Bsum.end(),S)-lower_bound(Bsum.begin(),Bsum.end(),S);
	}
	cout<<count;
}