#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int N,M;
vector<long long> A;
int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>N>>M;
	A.resize(M);
	for(int i=0;i<M;++i){
		long long  a;
		cin>>a;
		if(i==0){
			A[i]=a;
		}else{
			A[i]=a+A[i-1];
		}
	}
	for(int i=0;i<N;++i){
		long long b;
		cin>>b;
		auto iter=lower_bound(A.begin(),A.end(),b);
		if(iter==A.end()){
			cout<<"Go away!"<<'\n';
		}else{
			cout<<iter-A.begin()+1<<'\n';
		}
	}
	
	
}