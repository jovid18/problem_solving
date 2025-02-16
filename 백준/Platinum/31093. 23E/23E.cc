#include <bits/stdc++.h>
using namespace std;
#define int long long
using pii=pair<int,int>;
int N,K;
string S;
int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>N>>K>>S;
    int c2,c3,ce;
    vector<pii> v;
    for(int i=0;i<N/2;++i){
        int a=0,b=0;
        if(S[i]=='2') a=0;
        else if(S[i]=='3') a=1;
        else a=-1;
        if(S[N-1-i]=='2') b=0;
        else if(S[N-1-i]=='3') b=1;
        else b=-1;
        v.push_back({a,b});
    }
    int score=0;
    int m2=0,m1=0,p1=0,p2=0;
    for(auto e: v){
        if(e.first+e.second==0) score+=2;
        else if(e.first+e.second==-2) m2++;
        else if(e.first+e.second==-1) m1++;
        else if(e.first+e.second==1) p1++;
        else if(e.first+e.second==2) p2++;
    }
    cout<<score<<'\n';
    for(int i=1;i<=K;++i){
        if(m2>0&&p2>0){
            m2--;
            p2--;
            score+=4;
        }else if(m1>0&&p1>0){
            m1--;
            p1--;
            score+=4;
        }else if(m1>1){
            m1-=2;
            m2++;
            score+=2;
        }else if(p1>1){
            p1-=2;
            p2++;
            score+=2;
        }else if(m2>0&&p1>0){
            m2--;
            p1--;
            m1++;
            score+=2;
        }else if(p2>0&&m1>0){
            p2--;
            m1--;
            score+=2;
        }
        cout<<score<<'\n';
    }
}