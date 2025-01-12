#include <bits/stdc++.h>
using namespace std;
#define int long long
int t;
int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int lowbnd=-1,upbnd=1E10;;
        vector<int> inhibit;
        for(int i=0;i<n;++i){
            int a,x;
            cin>>a>>x;
            if(a==1){
                lowbnd=max(lowbnd,x);
            }else if(a==2){
                upbnd=min(upbnd,x);
            }else{
                inhibit.push_back(x);
            }
        }
        sort(inhibit.begin(),inhibit.end());
        int ans=0;
        if(lowbnd>upbnd) cout<<0<<'\n';
        else{
            ans=upbnd-lowbnd+1;
            for(auto e:inhibit){
                if(e<lowbnd||e>upbnd) continue;
                else ans--;
            }
            cout<<ans<<'\n';
        }
    }
}