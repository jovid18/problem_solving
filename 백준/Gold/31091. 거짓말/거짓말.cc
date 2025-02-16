#include <bits/stdc++.h>
using namespace std;
#define int long long
int N;
int p[500001],m[500001];
int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>N;
    for(int i=1;i<=N;++i){
        int x;
        cin>>x;
        if(x>0) p[x]++;
        if(x<=0) m[-x]++;
    }
    int psum=0;
    int msum=0;
    for(int i=1;i<=N;++i){
        psum+=p[i];
    }
    int cnt=0;
    vector<int> ans;
    for(int i=0;i<=N;++i){
        psum-=p[i];
        if(i>=1) msum+=m[i-1];
        // cout<<i<<" "<<psum+msum<<'\n';
        if(i==psum+msum){
            cnt++;
            ans.push_back(i);
        }
    }
    cout<<cnt<<'\n';
    for(auto e:ans) cout<<e<<" ";
}