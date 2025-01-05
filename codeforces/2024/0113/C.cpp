#include <bits/stdc++.h>
using namespace std;
#define int long long
int t;
int n;
vector<int> a;
int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>t;
    while(t--){
        // cout<<8-t<<"번째 케이스\n";
        cin>>n;
        a.resize(n);
        for(auto &e: a) cin>>e;
        int ans=1;
        for(int k=1;k<n;++k){
            if(n%k!=0) continue;
            bool isp=true;
            bool onlyminusone=true;
            vector<int> total;
            for(int i=0;i<k;++i){
                vector<int> now;
                for(int j=i+k;j<n;j+=k){
                    now.push_back(abs((a[j]-a[i])));
                }
                int nownum=-1;
                for(auto e: now) {
                    if(e==0) continue;
                    if(nownum==-1) nownum=e;
                    else{
                        nownum=__gcd(nownum,e);
                    }
                }
                // cout<<k<<" "<<nownum<<'\n';
                if(nownum==1) isp=false;
                if(nownum!=1&&nownum!=-1)total.push_back(nownum);
                // if(nownum!=-1) onlyminusone=false;
            }
            if(!isp) continue;
            if(total.empty()){
                ans++;
            }else{
                int now=total[0];
                for(auto e: total){
                    now=__gcd(now,e);
                }
                if(now==1) continue;
                else ans++;
            }

        }
        cout<<ans<<'\n';
    }

}