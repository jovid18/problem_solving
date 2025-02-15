#include <bits/stdc++.h>
using namespace std;
#define int long long
const int V=2e5+1;
int N,G;
int a[V],r[V];
struct DSU{
    int par[V], sz[V];
    DSU(){}
    void init(int n) {
        for (int i = 1; i<=n; i++)
        par[i] = i, sz[i] = 1;
    }
    int find(int x) {
        return x == par[x] ? x : (par[x] = find(par[x]));
    }
    bool unite(int x, int y) {
        int u=find(x), v=find(y);
        if(u==v) return false;
        G--;
        if(sz[u]>sz[v]) swap(u, v);
        sz[v]+=sz[u];
        sz[u] = 0;
        par[u] = par[v];
        return true;
    }
};
DSU dsu;
int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>N;
    for(int i=1;i<=N;++i){
        cin>>a[i];
        r[a[i]]=i;
    } 
    G=N;
    dsu.init(N);
    vector<pair<int,int>> swaprec;
    for(int i=1;i<=N;++i){
        dsu.unite(i,a[i]);
    }
    if(G==1){
        cout<<0<<" "<<0;
        return 0;
    }
    cout<<G-1<<" "<<G-1<<'\n';
    while(G!=1){
        for(int i=1;i<N;++i){
            if(dsu.find(i)!=dsu.find(i+1)){
                swaprec.push_back({r[i],r[i+1]});
                swap(r[i],r[i+1]);
                a[r[i]]=i;
                a[r[i+1]]=i+1;
                dsu.unite(i,i+1);
            }
        }
    }
    for(auto e:swaprec){
        cout<<e.first<<" "<<e.second<<'\n';
    }
}