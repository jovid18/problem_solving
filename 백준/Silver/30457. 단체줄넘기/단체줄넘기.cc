#include <bits/stdc++.h>
using namespace std;
#define int long long
int N;
vector<int> V;
int32_t main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N;
    V.resize(N);
    for(int i=0;i<V.size();++i){
        cin>>V[i];
    }
    sort(V.begin(),V.end());
    int ans=0;
    for(int i=1;i<=1000;++i){
        int sam=upper_bound(V.begin(),V.end(),i)-lower_bound(V.begin(),V.end(),i);
        ans+=min(sam,2LL);
    }
    cout<<ans;
}
