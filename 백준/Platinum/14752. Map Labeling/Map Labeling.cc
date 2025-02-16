#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
int n;
int DP[10001][10001];
vector<pii> L;
int INF=0x3f3f3f3f;
int NINF=-INF;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    cin>>n;
    L.resize(n);
    memset(DP,0x3f,sizeof(DP));
    for(int i=0;i<n;++i) cin>>L[i].first;
    for(int i=0;i<n;++i) cin>>L[i].second;
    sort(L.begin(),L.end());
    DP[0][0]=NINF;
    for(int i=0;i<n;++i){
        for(int j=0;j<=i;++j){
            if(DP[i][j]==INF) continue;
            int &prepos=DP[i][j];
            int newpos=L[i].first;
            int width=L[i].second;
            if(prepos+width<newpos){
                DP[i+1][j]=min(DP[i+1][j],prepos+width);
                DP[i+1][j+1]=min(DP[i+1][j+1],newpos);
            }else if(newpos<prepos) DP[i+1][j]=min(DP[i+1][j],prepos+width);
            else DP[i+1][j+1]=min(DP[i+1][j+1],prepos+width);
        }
    }
    for(int i=n;i>=0;--i){
        if(DP[n][i]!=INF) {
            cout<<n-i;
            break;
        }
    }
}