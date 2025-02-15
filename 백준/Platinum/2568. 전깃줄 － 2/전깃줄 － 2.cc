#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<pair<int,int>> L;
vector<int> trashnum;
vector<int> A;
vector<int> D;
vector<int> B;
vector<int> Di;
vector<int> Ai;
vector<int> Bi;
vector<bool> T;
vector<int> X;
int main(){
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	cin>>N;
	L.resize(N);
	for(int i=0;i<N;++i){
		cin>>L[i].first>>L[i].second;
	}
	sort(L.begin(),L.end());
	A.resize(N+1);
	D.resize(N+1);
	B.resize(N+1);
	T.resize(N+1);
	A[0]=0;
	D[0]=0;
	B[0]=0;
	Di.push_back(0);
	Ai.push_back(0);
	Bi.push_back(0);
	for(int i=1;i<=N;++i){
		A[i]=L[i-1].second;
	}
	for(int i=1;i<=N;++i){
		auto iter=lower_bound(Ai.begin(),Ai.end(),A[i]);
		int n=iter-Ai.begin();
		if(iter==Ai.end()){
			Di.push_back(n);
			D[i]=Di[n];
			B[i]=Bi[n-1];
			Ai.push_back(A[i]);
			Bi.push_back(i);
		}else{
			D[i]=Di[n];
			Ai[n]=A[i];
			B[i]=Bi[n-1];
			Bi[n]=i;
		}
	}
	cout<<N-Di.back()<<endl;
	int last=Bi.back();
	while(last!=0){
		T[last]=true;
		last=B[last];
	}
	for(int i=1;i<=N;++i){
		if(T[i]) continue;
		cout<<L[i-1].first<<'\n';
	}
}