#include <bits/stdc++.h>
using namespace std;
#define int long long
using pii=pair<int,int>;
int T[100001];
int d[100001];
bool visited[100001];
int N,ans,d1,d2,d3,d11,d22,d33,s1,s2,s3;
vector<vector<pii>> G;
pii maxd;
bool leaf(int n){
    return T[n]==1;
}
void dfs(int n,int p){
    for(auto e:G[n]){
        if(visited[e.first]) continue;
        if(e.first==p) continue;
        d[e.first]=d[n]+1;
        if(maxd.first<d[e.first]) maxd={d[e.first],e.first}; 
        dfs(e.first,n);
    }
}
int findmid(int node){
    memset(d,0,sizeof(d));
    maxd={-1,0};
    dfs(node,0);
    memset(d,0,sizeof(d));
    int last=maxd.second;
    maxd={-1,0};
    dfs(last,0);
    for(int i=1;i<=N;++i){
        if(leaf(i)) continue;
        if(visited[i]) continue;
        if(d[i]==maxd.first/2) return i;
    }
    return 0;
} 
void dist(int nowd, int node,int p,int &s,int &dx,int &dxx){
    if(visited[node]) return;
    if(leaf(node)){
        s++;
        dx+=nowd;
        dxx+=nowd*nowd;
        return;
    }
    for(auto e: G[node]){
        if(visited[e.first]) continue;
        if(e.first==p) continue;
        dist(nowd+e.second,e.first,node,s,dx,dxx);
    }
}
void solve(int node,int p){
    if(leaf(node)) return ; 
    int ret=0;
    int mid=node;
    visited[mid]=true;
    vector<pii> adj;
    for(auto e: G[mid]){
        if(visited[e.first]) continue;
        if(e.first==p) continue;
        adj.push_back({e.first,e.second});
    }
    if(adj.size()<=1) return;
    d1=0,d2=0,d3=0,d11=0,d22=0,d33=0,s1=0,s2=0,s3=0;
    if(adj.size()==2){
        dist(adj[0].second,adj[0].first,0,s1,d1,d11);
        dist(adj[1].second,adj[1].first,0,s2,d2,d22);
        ans+=s2*d11+s1*d22+2*d1*d2;
    }else if(adj.size()==3){
        dist(adj[0].second, adj[0].first,0,s1,d1,d11);
        dist(adj[1].second, adj[1].first,0,s2,d2,d22);
        dist(adj[2].second, adj[2].first,0,s3,d3,d33);
       ans+=(s2+s3)*d11+(s1+s3)*d22+(s1+s2)*d33+2*d1*d2+2*d2*d3+2*d1*d3;
    }
    for(auto e:adj){
        solve(e.first,node);
    }
}
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    cin>>N;
    G.resize(N+1);
    for(int i=1;i<N;++i){
        int a,b,c;
        cin>>a>>b>>c;
        T[a]++;
        T[b]++;
        G[a].push_back({b,c});
        G[b].push_back({a,c});
    }
    for(int i=1;i<=N;++i){
        if(T[i]>1){
            solve(i,0);
            break;
        }
    }
    cout<<ans;
}