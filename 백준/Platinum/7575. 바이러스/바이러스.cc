#include <bits/stdc++.h>
using namespace std;
int N,K;
vector<int> V[200];
vector<int> getPi(vector<int> p) {
    int j = 0, plen = p.size();
    vector<int> pi;
    pi.resize(plen);
    for(int i = 1; i< plen; i++) {
        while((j > 0) && (p[i] != p[j])) j = pi[j-1];
        if(p[i] == p[j]) {
            j++;
            pi[i] = j;
        }
    }
    return pi;
}
vector <int> kmp(vector<int> s, vector<int> p) {
    vector<int> ans;
    auto pi = getPi(p);
    int slen = s.size(), plen = p.size(), j = 0;
    for(int i = 0 ; i < slen ; i++) {
        while(j>0 && s[i] != p[j])
            j = pi[j-1];
            if(s[i] == p[j]) {
                if(j==plen-1) {
                    ans.push_back(i-plen+1);
                    j = pi[j];
                }
            else j++;
        }
    }
    return ans;
}

int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>N>>K;
    for(int i=0;i<N;++i){
        int x;
        cin>>x;
        V[i].resize(x);
        for(auto &e: V[i]) cin>>e;
    }
    auto stand=V[0];
    for(int i=0;i<N;++i){
        V[i+N]=V[i];
        reverse(V[i+N].begin(),V[i+N].end());
    }
    bool ans=false;
    for(int i=0;i<stand.size();++i){
        if(i+K-1==stand.size()) break;
        vector<int> p;
        for(int j=i;j<i+K;++j){
            p.push_back(stand[j]);
        }
        bool imp=false;
        for(int i=0;i<N;++i){
            auto res1=kmp(V[i],p);
            auto res2=kmp(V[i+N],p);
            if(res1.size()==0&&res2.size()==0){
                imp=true;
                break;
            }
        }
        if(!imp) ans=true; 
    }
    if(ans) cout<<"YES";
    else cout<<"NO";
 }