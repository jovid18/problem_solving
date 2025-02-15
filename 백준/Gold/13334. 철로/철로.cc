#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int N,d;
vector<pair<int,int>> H;
bool compare(pair<int,int> a,pair<int,int> b){
	if(a.second==b.second){
		return a.first<b.first;
	}
	return a.second<b.second;
}
priority_queue<int, vector<int>, greater<int>> pq;
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	for(int i=0;i<N;++i){
		int a,b;
		cin>>a>>b;
		if(a>b) swap(a,b);
		H.push_back({a,b});
	}
	cin>>d;
	sort(H.begin(),H.end(),compare);
	int s,f;
	int count=0;
	for(int i=0;i<H.size();++i){
		if(H[i].second-H[i].first>d) continue;
		f=H[i].second;
		s=f-d;
		pq.push(H[i].first);
		while(!pq.empty()&&(pq.top()<s||pq.top()>f)){
			pq.pop();
		}
		count=max(count,(int)pq.size());
	}
	cout<<count;
}