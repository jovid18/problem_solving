#include <bits/stdc++.h>
using namespace std;
#define int long long
int t;
int x[4],y[4];
int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>t;
    while(t--){
        int xmin=2000,xmax=-2000,ymin=20000,ymax=-2000;
        for(int i=0;i<4;++i){
            int a,b;
            cin>>a>>b;
            xmin=min(xmin,a);
            xmax=max(xmax,a);
            ymin=min(ymin,b);
            ymax=max(ymax,b);
        }
        cout<<(xmax-xmin)*(ymax-ymin)<<'\n';
    }
}