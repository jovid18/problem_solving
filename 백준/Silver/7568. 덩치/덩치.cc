#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
using pii=pair<int,int>;
int N;
vector<pii> H,S;
int comp(pii &a, pii&b){
	if(a.first>b.first&&a.second>b.second) return 1;
	if(a.first<b.first&&a.second<b.second) return -1;
	return 0;
}
bool comp1(const pii &a, const pii &b){
	return a.second>b.second;
}
int main(){
	cin>>N;
	H.resize(N);
	S.resize(N);
	for(int i=0;i<N;++i){
		cin>>H[i].first>>H[i].second;
		S[i].first=i;
	}
	for(int i=0;i<N;++i){
		for(int j=i+1;j<N;++j){
			int x=comp(H[i],H[j]);
			if(x==1) S[j].second++;
			if(x==-1) S[i].second++;
		}
	}
	for(auto e:S){
		cout<<e.second+1<<" ";
	}
}