#include <bits/stdc++.h>
using namespace std;
int N;
string s,p;
vector<int> getPi(string p) {
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
vector <int> kmp(string s, string p) {
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
    cin>>s>>p;
    s+=s;
    s.pop_back();
    auto res=kmp(s,p);
    cout<<res.size();
}