#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int N,K;
priority_queue<int, vector<int>, less<int>> pq;
vector<int> bag;
vector<pair<int,int>> jewellist;
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>K;
	for(int i=0;i<N;++i){
		int a,b;
		cin>>a>>b;
		jewellist.push_back({a,b});
	} 
	for(int i=0;i<K;++i){
		int a;
		cin>>a;
		bag.push_back(a);	
	}
	sort(bag.begin(),bag.end());
	sort(jewellist.begin(),jewellist.end());
	long long maxvalue=0;
	auto jeweliter=jewellist.begin();
	for(int i=0;i<K;++i){
		while((*jeweliter).first<=bag[i]&&jeweliter!=jewellist.end()){
			pq.push((*jeweliter).second);
			jeweliter++;	
		}
		if(pq.empty()) continue;
		maxvalue+=pq.top();
		pq.pop();
	}
	cout<<maxvalue;
}
