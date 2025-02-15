#include <bits/stdc++.h>
using namespace std;
#define int long long
using pii=pair<int,int>;
int N;
vector<pii> T;
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    cin>>N;
    T.resize(N);
    for(int i=0;i<N;++i){
        cin>>T[i].first>>T[i].second;
        T[i].second+=T[i].first;
    } 
    sort(T.begin(),T.end());
    int s=0, f=2e9+1;
    while(s+1<f){
        int m=(s+f)/2;
        int now=T[0].first;
        bool ok=true;
        for(int i=1;i<N;++i){
            if(T[i].second<now+m){
                ok=false;
                break;
            }else if(T[i].first<=now+m&&now+m<=T[i].first+T[i].second) now+=m;
            else now=T[i].first;
        }
        if(ok) s=m; 
        else f=m-1;
    }
    int now=T[0].first;
    bool ok=true;
    for(int i=1;i<N;++i){
            if(T[i].second<now+f){
                ok=false;
                break;
            }else if(T[i].first<=now+f&&now+f<=T[i].first+T[i].second) now+=f;
            else now=T[i].first;
    }
    if(ok) cout<<f; 
    else cout<<s;
}