#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> A;
int W,N;
bool check;
bool S[400001];
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>W>>N;
	A.resize(N);
	for(int i=0;i<N;++i){
		cin>>A[i];
	}
	sort(A.begin(),A.end());
	for(int i=2;i<N-1;++i){
		for(int j=0;j<i-1;++j){
			S[A[j]+A[i-1]]=true;
		}
		for(int j=i+1;j<N;++j){
			if(W-A[i]-A[j]<0||W-A[i]-A[j]>400000) break;
			if(S[W-A[i]-A[j]]){
				check=true;
				break;
			}
		}
		if(check) break;
	}
	
	if(check){
		cout<<"YES"<<'\n';
	}else{
		cout<<"NO"<<'\n';	
	}
}