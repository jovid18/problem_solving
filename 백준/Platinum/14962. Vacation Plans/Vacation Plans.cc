    #include <bits/stdc++.h>
    using namespace std;
    #define int long long
    using pii=pair<int,int>;
    const int INF=1LL<<62;
    int p;
    int n[3],m[3],h[3];
    vector<vector<vector<pii>>> G;
    vector<vector<int>> DP;
    int32_t main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        cin>>p;
        G.resize(p);
        for(int i=0;i<p;++i){
            cin>>n[i]>>m[i];
            G[i].resize(n[i]+1);
            for(int j=1;j<=n[i];++j){
                int x;
                cin>>x;
                G[i][j].push_back({j,x});
            }
            for(int j=0;j<m[i];++j){
                int u,v,w;
                cin>>u>>v>>w;
                G[i][u].push_back({v,w});
            }
            cin>>h[i];
        }
        DP.resize(p);
        for(int i=0;i<p;++i){
            DP[i].assign(n[i]+1,-1);
            DP[i][1]=0;
        }
        int ans=INF;
        int t=1;
        while(t<=125000){
            for(int i=0;i<p;++i){
                vector<int> SDP(n[i]+1,INF);
                for(int j=1;j<=n[i];++j){
                    if(DP[i][j]==-1) continue;
                    for(auto e: G[i][j]){
                        SDP[e.first]=min(SDP[e.first],DP[i][j]+e.second);
                    }
                }
                DP[i]=SDP;
                for(auto &e:DP[i]){
                    if(e==INF) e=-1;
                }
            }
            bool pass=true;
            int cost=0;
            for(int i=0;i<p;++i){
                if(DP[i][h[i]]!=-1) cost+=DP[i][h[i]];
                else pass=false;
            }
            if(pass) ans=min(ans,cost);
            t++;
        }
        cout<<ans;
    }