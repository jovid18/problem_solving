#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
int32_t main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    int x=n/2+1;
    cout<<2*(x-2)*(n-x)<<'\n';
    for(int i=2;i<=x;++i){
        cout<<1<<" "<<i<<'\n';
    }
    cout<<2<<" "<<x+1<<'\n';
    for(int i=x+1;i<n;++i){
        cout<<i<<" "<<i+1<<'\n';
    }
}
