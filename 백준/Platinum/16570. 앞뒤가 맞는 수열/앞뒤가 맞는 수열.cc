#include <bits/stdc++.h>
using namespace std;
#define int long long
int N;
vector<int> a;
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
    cin>>N;
    a.resize(N);
    for(auto &e:a) cin>>e;
    reverse(a.begin(),a.end());
    auto res=kmp(a,a);
    int s=1,f=N;
    pair<int,int> ans={-1,-1};
    while(s+1<f){
        int m=(s+f)/2;
        vector<int> p;
        p.insert(p.begin(),a.begin(),a.begin()+m);
        auto res=kmp(a,p);
        if(res.size()>1){
            ans={m,res.size()-1};
            s=m;
        }else{
           f=m-1;
        }
    }
    vector<int> res1,res2;
    {
        vector<int> p;
        p.insert(p.begin(),a.begin(),a.begin()+f);
        auto res=kmp(a,p);
        if(res.size()>1){
            cout<<f<<" "<<res.size()-1;
            return 0;
        }
    }
    {
        vector<int> p;
        p.insert(p.begin(),a.begin(),a.begin()+s);
        auto res=kmp(a,p);
        if(res.size()>1){
            cout<<s<<" "<<res.size()-1;
            return 0;
        }
    }
    cout<<-1;
}