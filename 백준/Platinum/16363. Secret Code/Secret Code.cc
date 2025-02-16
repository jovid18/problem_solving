    #include <bits/stdc++.h>
    using namespace std;
    #define int long long
    struct agent{
        int S,wa,wb,wc,idx;
    };
    int n;
    int c(int x){
        return x*x*x;
    }
    int u(int S, int a, int b){
        return c(S)-c(S-a)-c(S-b)+c(S-a-b);
    }
    bool comp(const agent &a, const agent &b){
        int au=u(a.S,a.wa,a.wb)+u(a.S,a.wb,a.wc)+u(a.S,a.wc,a.wa);
        int bu=u(b.S,b.wa,b.wb)+u(b.S,b.wb,b.wc)+u(b.S,b.wc,b.wa);
        int ad=c(a.S);
        int bd=c(b.S);
        if(au*bd==ad*bu) return a.idx<b.idx;
        return au*bd<ad*bu;
    }
    vector<agent> V;
    int32_t main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        cin>>n;
        V.resize(n);
        for(int i=0;i<n;++i){
            cin>>V[i].S>>V[i].wa>>V[i].wb>>V[i].wc;
            V[i].idx=i+1;
        }
        sort(V.begin(),V.end(),comp);
        for(auto e:V){
            cout<<e.idx<<" ";
        }
    }