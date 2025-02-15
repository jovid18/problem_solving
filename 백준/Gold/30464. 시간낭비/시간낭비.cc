#include <bits/stdc++.h>
using namespace std;
#define int long long
int N;
int a[200002], DP[200002];
int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>N;
    for(int i=1;i<=N;++i){
        DP[i]=-1;
        cin>>a[i];
    } 
    DP[1]=0;
    for(int i=1;i<=N-1;++i){
        if(DP[i]==-1) continue;
        if(a[i]==0) continue;
        if(i+a[i]<=N) DP[i+a[i]]=max(DP[i+a[i]],DP[i]+1);
    }
    for(int i=N-1;i>=1;--i){
        if(DP[i]==-1) continue;
        if(a[i]==0) continue;
        if(i-a[i]>=1) DP[i-a[i]]=max(DP[i-a[i]],DP[i]+1);
    }
    for(int i=1;i<=N-1;++i){
        if(DP[i]==-1) continue;
        if(a[i]==0) continue;
        if(i+a[i]<=N) DP[i+a[i]]=max(DP[i+a[i]],DP[i]+1);
    }
    cout<<DP[N];
}