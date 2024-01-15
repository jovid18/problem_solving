#include <bits/stdc++.h>
using namespace std;
#define int long long
int t;
int n,m;
vector<int> a,b;
int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>t;
    while(t--){
        cin>>n>>m;
       
        a.resize(n);
        b.resize(m);
        for(auto &e: a) cin>>e;
        for(auto &e: b) cin>>e;
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        int as=0,af=n-1,bs=0,bf=m-1;
        int ans=0;
        for(int i=0;i<n;++i){
            if(abs(b[bf]-a[as])>abs(a[af]-b[bs])){
                ans+=abs(b[bf]-a[as]);
                bf--;
                as++;
            }else{
                ans+=abs(a[af]-b[bs]);
                bs++;
                af--;
            }
        }
        cout<<ans<<'\n';
    }
}