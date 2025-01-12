#include <bits/stdc++.h>
using namespace std;
#define int long long
int t;
int n,k,x;
vector<int> a;
int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>t;
    while(t--){
        cin>>n>>k>>x;
        a.resize(n);
        for(auto &e:a){
            cin>>e;
        }
        sort(a.begin(),a.end(),greater<>());
        // for(auto e: a) cout<<e<<" ";
        int ans=0;
        int sum=0;
        for(int i=0;i<x;++i){
            sum-=a[i];
        }
        for(int i=x;i<n;++i){
            sum+=a[i];
        }
        ans=sum;
        // cout<<ans<<'\n';
        for(int i=0;i<k;++i){
            sum+=a[i];
            if(i+x<n) sum-=2*a[i+x];
            ans=max(ans,sum);
            // cout<<sum<<'\n';
        }
        cout<<ans<<'\n';
    }

}