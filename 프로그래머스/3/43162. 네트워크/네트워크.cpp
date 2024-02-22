#include <string>
#include <vector>
using namespace std;
const int MAXV=201;
int par[MAXV],siz[MAXV];

int find(int x){
    return x==par[x] ? x: (par[x]=find(par[x]));
}
bool unite(int x, int y){
    int u=find(x), v=find(y);
    if(u==v) return false;
    if(siz[u]>siz[v]) swap(u,v);
    siz[v]+=siz[u];
    par[u]=par[v];
    return true;
}
int solution(int n, vector<vector<int>> computers) {
    for(int i=0;i<n;++i){
     par[i]=i;
     siz[i]=1;
    }
    int answer = n;
    for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j){
            if(computers[i][j]){
                if(unite(i,j)) answer--;
            }
        }
    }
    return answer;
}