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
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    priority_queue<pii,vector<pii>,bool(*)(pii,pii)> pq(cmp);
    int idx=0;
    int ans=0;
    for(auto &[val,cnt]:b){
        while(idx<N&&a[idx].first<=val){
            if(val<=a[idx].second){
                pq.push(a[idx]);
            }
            idx++;
        }
        while(cnt&&!pq.empty()){
            if(pq.top().first<=val&&val<=pq.top().second){
                cnt--;
                ans++;
            }
            pq.pop();
        }
    }
    cout<<ans;
}