#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
int O[100001];
int E[100001];
vector<pair<int,int>> W;
int o=1,e=1;
int main(){
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	cin>>N;
	W.resize(N);
	for(int i=0;i<N;++i){
		cin>>W[i].first>>W[i].second;
	}
	sort(W.begin(),W.end());
	bool P=false;
	for(int i=1;i<=N;++i){
		int d=W[i-1].first;
		int t=W[i-1].second;
		for(int j=o;j<=d&&t>0;++j){
			o++;
			if(j%7==0||j%7==6) continue;
			O[j]=i;
			t--;
		}
		if(t==0) continue;
		for(int j=e;j<=d&&t>0;++j){
			e++;
			E[j]=i;
			t--;
		}
		if(t>0){
			P=true;
			break;
		}
	}
	if(P){
		cout<<-1;
	}else{
		cout<<e-1;
	}
}