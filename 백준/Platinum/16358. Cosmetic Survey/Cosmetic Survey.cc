#include <bits/stdc++.h>
using namespace std;
using pip=pair<int,pair<int,int>>;
int n,m;
vector<vector<int>> P;
int d[500][500];
int s[500][500];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    cin>>m>>n;
    P.resize(n);
    for(int i=0;i<n;++i){
        P[i].resize(m);
        for(int j=0;j<m;++j){
            cin>>P[i][j];
            if(P[i][j]==0) P[i][j]=1e7;
        }
    }
    for(int i=0;i<m;++i){
        for(int j=i+1;j<m;++j){
            for(int k=0;k<n;++k){
                if(P[k][i]>P[k][j]) d[j][i]++;
                if(P[k][i]<P[k][j]) d[i][j]++;
            }
        }
    }
    for(int i=0;i<m;++i){
        for(int j=i+1;j<m;++j){
            if(d[i][j]>d[j][i]) d[j][i]=0;
            else if(d[i][j]<d[j][i]) d[i][j]=0;
            else{
                d[i][j]=0;
                d[j][i]=0;
            }
        }
    }
    for(int i=0;i<m;++i){
        d[i][i]=1e7;
    }
    for(int k=0;k<m;++k){
        for(int i=0;i<m;++i){
            for(int j=0;j<m;++j){
                d[i][j]=max(d[i][j],min(d[i][k],d[k][j]));
            }
        }
    }
    for(int i=0;i<m;++i){
        bool chk=true;
        for(int j=0;j<m;++j){
            if(i==j) continue;
            if(d[i][j]<d[j][i]){
                chk=false;
                break;
            }
        }
        if(chk) cout<<i+1<<" ";
    }
}