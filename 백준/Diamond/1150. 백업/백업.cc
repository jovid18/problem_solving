#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
const int MAXN=100002;
const int INF=0x3f3f3f3f;
int A[MAXN];
int d[MAXN];
int l[MAXN];
int r[MAXN];
int N,K;
bool checked[MAXN];
priority_queue<pii,vector<pii>, greater<>> pq;
int32_t main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N>>K;
    for(int i=1;i<=N;++i){
        cin>>A[i];
        l[i]=i-1;
        r[i]=i+1;
        if(i>1) d[i]=A[i]-A[i-1];
    }
    d[1]=INF;
    d[N+1]=INF;
    l[N+1]=N;
    for(int i=1;i<=N+1;++i){
        pq.push({d[i],i});
    }
    int cpp=0;
    int ans=0;
    while(cpp<K){
        auto ptop =pq.top();
        auto dist=ptop.first;
        auto idx=ptop.second;
        pq.pop();
        if(checked[idx]) continue;
        cpp++;
        ans+=dist;
        d[idx]=d[l[idx]]+d[r[idx]]-d[idx];
        pq.push({d[idx],idx});
        checked[l[idx]]=1;
        checked[r[idx]]=1;
        l[idx]=l[l[idx]];
        r[idx]=r[r[idx]];
        l[r[idx]]=r[l[idx]]=idx;
    }
    cout<<ans;
}
