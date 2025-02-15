#include <bits/stdc++.h>
using namespace std;
int n,A[250],B[250];
int DP[251][62501];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>A[i]>>B[i];
    }
    memset(DP,0x3f3f3f3f,sizeof(DP));
    DP[0][0]=0;
    for(int i=0;i<n;++i){
        for(int j=0;j<=62500;++j){
            if(DP[i][j]>=0x3f3f3f3f) continue;
            DP[i+1][j+A[i]]=min(DP[i+1][j+A[i]],DP[i][j]);
            DP[i+1][j]=min(DP[i+1][j],DP[i][j]+B[i]);
        }
    }
    int ans=0x3f3f3f3f;
    for(int j=0;j<=62500;++j){
        ans=min(ans,max(DP[n][j],j));
    }
    cout<<ans;
}