#include <bits/stdc++.h>
using namespace std;
#define int long long
int N,M,Q;
int A[2001][2001];
int C[2001][2001];
int S[2001][2001];
int W,P;
int32_t main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N>>M>>Q;
    for(int i=1;i<=N;++i){
        for(int j=1;j<=M;++j){
            cin>>A[i][j];
        }
    }
    for(int i=1;i<=N;++i){
        for(int j=1;j<=M;++j){
            if(i==1){
                C[i][j]=A[i][j];
            }else{
                C[i][j]=A[i][j]+C[i-1][j];
            }
        }
    }
    for(int i=1;i<=N;++i){
        for(int j=1;j<=M;++j){
            if(i==1){
                S[i][j]=C[i][j];
            }else{
                S[i][j]=C[i][j]+S[i-1][j-1];
            }
        }
    }
    while(Q--){
        cin>>W>>P;
        cout<<S[W][P]<<'\n';
    }
}
