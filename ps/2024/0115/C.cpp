#include <bits/stdc++.h>
using namespace std;
#define int long long
int t;
int n,f,a,b;
int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>t;
    while(t--){
        cin>>n>>f>>a>>b;
        vector<int> m;
        m.resize(n+1);
        m[0]=0;
        for(int i=1;i<=n;++i) cin>>m[i];
        for(int i=0;i<n;++i){
            f-=min(a*(m[i+1]-m[i]),b);
        }
        if(f>0) cout<<"YES\n";
        else cout<<"NO\n";
    }
}