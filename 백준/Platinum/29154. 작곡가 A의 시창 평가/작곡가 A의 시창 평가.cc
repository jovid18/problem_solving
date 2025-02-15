#include <bits/stdc++.h>
using namespace std;
#define int long long
int N, M, Cnt;
vector<int> S, L, X;
vector<bool> Chk;
vector<int> getPi(vector<int> p){
    int j=0, plen = p.size();
    vector<int> pi;
    pi.resize(plen);
    for (int i = 1; i < plen; i++){
        while ((j > 0) && (p[i] != p[j])) j = pi[j - 1];
        if (p[i] == p[j]){
            j++;
            pi[i] = j;
        }
    }
    return pi;
}

void kmp(vector<int> s, vector<int> p){
    auto pi = getPi(p);
    int slen = s.size(), plen = p.size(), j = 0;
    for (int i = 0; i < slen; i++){
        while (j > 0 && s[i] != p[j]) j = pi[j - 1];
        if (s[i] == p[j])
        {
            if (j == plen - 1){
                Chk[i]=1;
                j = pi[j];
                continue;
            } 
            else j++;
        }
        Chk[i]=j;
    }
}
int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    S.resize(N);
    L.resize(M);
    Chk.resize(N);
    for (auto &e : S) cin >> e;
    for (auto &e : L) cin >> e;
    reverse(S.begin(), S.end());
    reverse(L.begin(), L.end());
    kmp(S,L);
    Chk.push_back(0);
    int Xor=0;
    for(int i=0,l=0;i<Chk.size();++i){
        if(Chk[i]) l++;
        else{
            if(l==0) continue;
            Xor^=l;
            l=0;
        }
    }
    if(Xor) cout<<"First";
    else cout<<"Second";
}