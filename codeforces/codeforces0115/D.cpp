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
         if(n==1){
            cout<<max(abs(b[0]-a[0]),abs(b[m-1]-a[0]))<<'\n';
            continue;
        }
        int s=0,f=m-1;
        int ans=0;
        int cnt=0;
        while(2*cnt+1<n){
            ans+=abs(b[f]-a[cnt]);
            ans+=abs(b[s]-a[n-1-cnt]);
            cnt++;
            s++;
            f--;
        }
        // cout<<cnt<<" "<<ans<<" ";
        // cout<<s<<" "<<f<<'\n';
        if(n%2==1){
            ans+=max(abs(b[f]-a[(n-1)/2]),abs(b[s]-a[(n-1)/2]));
        }
        cout<<ans<<'\n';
    }
}