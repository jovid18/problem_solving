#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int N;
using pii=pair<int,int>;
vector<pii> C;
priority_queue<int,vector<int>,greater<int>> pq;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	C.resize(N);
	for(int i=0;i<N;++i){
		cin>>C[i].first>>C[i].second;
	}
	sort(C.begin(),C.end());
	for(int i=0;i<N;++i){
		if(pq.empty()){
			pq.push(C[i].second);
		}else{
			if(pq.top()<=C[i].first){
				pq.pop();
				pq.push(C[i].second);
			}else{
				pq.push(C[i].second);
			}
		}
	}
	cout<<pq.size();
}
