#include <bits/stdc++.h>
using namespace std;
#define int long long
int N;
vector<int> A;
int sum[200003];
int DP[200003];
int32_t main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N;
    A.resize(N);
    int ans=0;
    for(int i=0;i<N;++i){
        cin>>A[i];
        ans+=A[i];
    }
    int s=A[0]+A[1]+A[2];
    sum[1]=s;
    for(int i=1;i<N-2;++i){
        s+=A[i+2];
        s-=A[i-1];
        sum[i+1]=s;
    }
    sum[N-1]=A[N-2]+A[N-1];
    sum[N]=A[N-1];
    int subans=0;
    for(int i=1;i<=N;++i){
        DP[i]=DP[i-1];
        if(i<4){
            DP[i]=max(DP[i],sum[i]);
        }else{
            DP[i]=max(DP[i],DP[i-3]+sum[i]);
        }
        subans=max(subans,DP[i]);
    }

    cout<<ans+subans;
}
