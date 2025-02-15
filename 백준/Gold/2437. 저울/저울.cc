#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector<int> W;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	W.resize(N);
	for(int i=0;i<N;++i){
		cin>>W[i];
	}
	sort(W.begin(),W.end());
	if(W[0]>1){
		cout<<1;
		return 0;
	}
	if(N==1){
		if(W[0]==1) cout<<2;
		return 0;
	}
	int sum=W[0];
	for(int i=1;i<N;++i){
		if(sum+1<W[i]){
			cout<<sum+1;
			return 0;
		}else sum+=W[i];
	}
	cout<<sum+1;
}