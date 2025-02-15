#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N,K,D;
vector<pair<int,int>> S;
vector<int> A;
int ans;
void eff(int s,int f){
	int a=A[S[s].second];
	int b=A[S[s].second];
	for(int i=s+1;i<=f;++i){
		a|=A[S[i].second];
		b&=A[S[i].second];
	}
	ans=max(ans,(__builtin_popcount(a)-__builtin_popcount(b))*(f-s+1));
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>K>>D;
	S.resize(N);
	A.assign(N,0);
	for(int i=0;i<N;++i){
		int know;
		cin>>know;
		cin>>S[i].first;
		S[i].second=i;
		for(int j=0;j<know;++j){
			int a;
			cin>>a;
			A[i]|=(1<<a);
		}
	}
	sort(S.begin(),S.end());
	int start=0,end=0;
	while(1){
		while(end!=N-1&&S[end+1].first-S[start].first<=D){
			end++;
		}
		eff(start,end);
		if(end==N-1) break;
		end++;
		while(S[end].first-S[start].first>D){
			start++;
		}
	}
	cout<<ans;
}
