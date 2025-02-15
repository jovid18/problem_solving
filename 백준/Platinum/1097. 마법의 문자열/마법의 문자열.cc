#include <bits/stdc++.h>
using namespace std;
int N;
vector<string> S;
int K;

vector<int> getPi(string p) {
    int j = 0, plen = p.length();
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
vector <int> kmp(string s, string p) {
    vector<int> ans;
    auto pi = getPi(p);
    int slen = s.length(), plen = p.length(), j = 0;
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
    cin>>N;
    S.resize(N);
    for(auto &e:S) cin>>e;
    cin>>K;
    vector<int> v(N);
    for(int i=0;i<N;++i) v[i]=i;
    int ans=0;
    do{
        string s;
        for(auto e:v){
            s+=S[e];
        }
        auto res=kmp(s+s,s);
        if(res.size()-1==K) ans++;
    }while(next_permutation(v.begin(),v.end()));
    cout<<ans;
 }