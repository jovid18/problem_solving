#include <bits/stdc++.h>
using namespace std;
#define all for(int i=1;i<=n;++i) for(int j=1;j<=n;++j)
int m[1001][1001],g[1001][1001];
int n;
void sprd(int x,int y){
    for(int i=-1;i<=1;++i){
        for(int j=-1;j<=1;++j){
            if(i==0&&j==0) continue;
            m[x+i][y+j]=max(0,m[x+i][y+j]-1);
        }
    }
}
int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>n;
    all g[i][j]=-1;
    for(int i=1;i<=n;++i) cin>>g[1][i];
    all cin>>m[i][j];
    for(int i=1;i<=n;++i){
        m[i][1]+=3;
        m[i][n]+=3;
        m[1][i]+=3;
        m[n][i]+=3;
    }
    m[1][1]--;
    m[1][n]--;
    m[n][1]--;
    m[n][n]--;
    all m[i][j]=8-m[i][j];
    for(int i=1;i<n;++i){
        for(int j=1;j<=n;++j){
            if(g[i][j]==1){
                sprd(i,j);
            }
        }
        if(m[i][1]==0){
            g[i+1][1]=0;
            g[i+1][2]=0;
            for(int j=2;j<n;++j){
                g[i+1][j+1]=m[i][j]-g[i+1][j-1]-g[i+1][j];
            }
        }else if(m[i][1]==2){
            g[i+1][1]=1;
            g[i+1][2]=1;
            for(int j=2;j<n;++j){
                g[i+1][j+1]=m[i][j]-g[i+1][j-1]-g[i+1][j];
            }
        }else{
            g[i+1][1]=0;
            g[i+1][2]=1;
            int prob=0;
            for(int j=2;j<n;++j){
                g[i+1][j+1]=m[i][j]-g[i+1][j-1]-g[i+1][j];
                if(1<g[i+1][j+1]||g[i+1][j+1]<0) prob=1;
            }
            if(m[i][n]!=g[i+1][n-1]+g[i+1][n]) prob=2;
            if(prob){
                g[i+1][1]=1;
                g[i+1][2]=0;    
                for(int j=2;j<n;++j){
                    g[i+1][j+1]=m[i][j]-g[i+1][j-1]-g[i+1][j];
                }
            }
        }
    }

    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            cout<<g[i][j]<<" ";
        }
        cout<<'\n';
    }
}