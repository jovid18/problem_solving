#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
int N,L;
vector<int> V;
deque<pii> dq;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    cin>>N>>L;
    V.resize(N);
    for(int i=0;i<N;++i){
        cin>>V[i];
    }
    for(int i=0;i<N;++i){
        while(!dq.empty()&&dq.back().first>V[i]){
            dq.pop_back();
        }
        dq.push_back({V[i],i});
        while(dq.front().second<=i-L){
            dq.pop_front();
        }
        cout<<dq.front().first<<" ";
    }
}