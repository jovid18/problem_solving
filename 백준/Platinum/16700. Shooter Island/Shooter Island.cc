#include <bits/stdc++.h>
using namespace std;
#define int long long
const int totn = 5300002;
const int toty = 100002;
int L;
int t,xa,xb,ya,yb;
int hashing(int x, int y){
    return x+50*y;
}
struct DSU
{
    vector<int> par, sz;
    void init(int n)
    {
        par.resize(n+1);
        sz.resize(n+1);
        for (int i = 0; i <= n; i++)
            par[i] = i, sz[i] = 1;
    }
    int find(int x)
    {
        return x == par[x] ? x : (par[x] = find(par[x]));
    }
    bool unite(int x, int y)
    {
        int u = find(x), v = find(y);
        if (u == v)
            return false;
        if (u<v)
            swap(u, v);
        sz[v] += sz[u];
        sz[u] = 0;
        par[u] = par[v];
        return true;
    }
};
DSU yuf[52];
DSU tuf;
bool chk[52][toty];
int32_t main()
{
    cin.tie(0)->sync_with_stdio(0);
    for(int i=0;i<52;++i) yuf[i].init(toty);
    tuf.init(totn);
    cin>>L;
    while(L--){
        cin>>t>>xa>>ya>>xb>>yb;
        int a=hashing(xa,ya);
        int b=hashing(xb,yb);
        if(t==0){
            if(xa>xb) swap(xa,xb);
            if(ya>yb) swap(ya,yb);
            for(int x=xa;x<=xb;++x){
                int y=ya;
                while(y<=yb){
                    int y0=y;
                    if(yuf[x].find(y)!=yuf[x].find(y+1)){
                        y++;
                    }else{
                        y=yuf[x].find(y)+yuf[x].sz[yuf[x].find(y)];
                    }
                    if(y<=yb){
                        chk[x][y]=true;
                        yuf[x].unite(y,y0);
                        tuf.unite(hashing(x,y),hashing(x,y0));
                    }
                    if(x==xa){
                        if(y0==ya){
                            if(chk[xa-1][y0]) tuf.unite(hashing(xa-1,y0),hashing(xa,y0));
                        }
                        if(chk[xa-1][y]) tuf.unite(hashing(xa-1,y),hashing(xa,y));
                    }
                    if(x==xb){
                        if(y0==ya){
                            if(chk[xb+1][y0]) tuf.unite(hashing(xb+1,y0),hashing(xb,y0));
                        }
                        if(chk[xb+1][y]) tuf.unite(hashing(xb+1,y),hashing(xb,y));
                    }
                    
                }
                chk[x][ya]=true;
            }
            for(int x=xa;x<xb;++x){
                tuf.unite(hashing(x,ya),hashing(x+1,ya));
            }
            for(int x=xa;x<=xb;++x){
                if(chk[x][ya-1]){
                    yuf[x].unite(ya,ya-1);
                    tuf.unite(hashing(x,ya),hashing(x,ya-1));
                }
                if(chk[x][yb+1]){
                    yuf[x].unite(yb,yb+1);
                    tuf.unite(hashing(x,yb),hashing(x,yb+1));
                }
            }

        }else{
            if(chk[xa][ya]&&chk[xb][yb]){ 
                int roota=tuf.find(a);
                int rootb=tuf.find(b);
                cout<<(roota==rootb)<<'\n';
                continue;
            }
            cout<<0<<'\n';
        }
    }
}