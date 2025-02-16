#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
string T,P;
int N;
vector<int> num;
vector<pair<int,int>> ans;
vector<int> findfail(vector<int> s){
	int m=s.size();
	vector<int> pi(m,0);
	int j=0;
	for(int i=1;i<m;++i){
		while(j>0&&s[i]!=s[j]){
			j=pi[j-1];
		}
		if(s[i]==s[j]){
			pi[i]=++j;
		}
	}
	return pi;
}
bool comp(const pair<int,int> &a,const pair<int,int> &b){
	if(a.first+a.second==b.first+b.second){
		return a.second<b.second;
	}else{
		return a.first+a.second<b.first+b.second;
	}
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	num.resize(N);
	for(int i=N-1;i>=0;--i){
		cin>>num[i];
	}
	auto fail=findfail(num);
	for(int i=0;i<=N-1;++i){
		ans.push_back({N-i-1,i+1-fail[i]});
	}
	sort(ans.begin(),ans.end(),comp);
	cout<<ans[0].first<<" "<<ans[0].second;
}
