#include <bits/stdc++.h>
using namespace std;
#define int long long
int t;
int n;
string a,b;
int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>t;
    while(t--){
        cin>>n>>a>>b;
        int zo=0,zz=0,oz=0,oo=0;
        for(int i=0;i<n;++i){
            if(a[i]=='0'){
                if(b[i]=='0'){
                    zz++;
                }else{
                    zo++;
                }
            }else{
                if(b[i]=='0'){
                    oz++;   
                }else{
                    oo++;
                }

            }
        }
        cout<<max(zo,oz)<<'\n';
    }
}