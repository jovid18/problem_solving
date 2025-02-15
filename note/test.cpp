#include <bits/stdc++.h>
using namespace std;
#define int long long
using pii=pair<int,int>;
int N,M;
vector<pii> a,b;
int32_t main(){
    auto cmp =[](pii x, pii y){
        if(x.second==y.second) return x.first>y.first;
        else return x.second>y.second;
    };
    cin.tie(0)->sync_with_stdio(0);
    cin>>N>>M;
    a.resize(N);
    b.resize(M);
    for(auto &[x,y]:a) cin>>x>>y;
    for(auto &[x,y]:b) cin>>x>>y;
    priority_queue<pii,vector<pii>,bool(*)(pii,pii)> pq(cmp);
    for(auto e: a) pq.push(e);
    while(!pq.empty()){
        cout<<pq.top().first<<" "<<pq.top().second<<'\n';
        pq.pop();
    }
}