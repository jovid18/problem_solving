#include <bits/stdc++.h>
using namespace std;
#define int long long
int N;
const int MaxN=200002;
int A[MaxN],B[MaxN];
bool used[MaxN];
int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>N;
    bool imp=false;
    for(int i=1;i<=N;++i){
        cin>>B[i];
        A[i]=-1;
        if(B[i-1]>B[i]) imp=true;
        if(B[i]>i+1) imp=true;
        if(i==N&B[i]!=N+1) imp=true; 
    }
    if(imp){
        cout<<"No";
        return 0;
    }
    for(int i=2;i<=N;++i){
        if(B[i]!=B[i-1]){
            A[i]=B[i-1];
            used[B[i-1]]=true;
        }
    }
    int highval=N;
    for(int i=N;i>=1;--i){
        while(used[highval]) highval--;
        if(A[i]!=-1) continue;
        A[i]=highval;
        highval--;
    }
    cout<<"Yes\n";
    for(int i=1;i<=N;++i) cout<<A[i]<<" ";
}