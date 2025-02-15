#include <bits/stdc++.h>
using namespace std;
#define int long long
int N,K;
vector<int> V;
string S;
int32_t main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    V.resize(1024);
    cin>>N>>K;
    for(int i=0;i<N;++i){
        cin>>S;
        int x=0;
        for(int i=0;i<10;++i){
            int bits=(S[i]-'0');
            x|=1<<bits;
        }
        V[x]++;
    }
    int ans=0;
    for(int i=0;i<1024;++i){
        for(int j=0;j<1024;++j){
            if(__builtin_popcount(i|j)==K){
                ans+=V[i]*V[j];
            }
        }
    }
    for(int i=0;i<1024;++i){
        if(__builtin_popcount(i)==K) ans-=V[i];
    }
    cout<<ans/2;
}
