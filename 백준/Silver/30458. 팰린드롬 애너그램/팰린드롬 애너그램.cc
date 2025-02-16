#include <bits/stdc++.h>
using namespace std;
#define int long long
int N;
string s;
vector<int> L(26,0),R(26,0);
int32_t main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N>>s;
    for(int i=0;i<N/2;++i){
        L[s[i]-'a']++;
    }
    for(int i=0;i<N/2;++i){
        L[s[N-1-i]-'a']++;
    }
    bool inc=false;
    for(int i=0;i<26;++i){
        if(L[i]%2==1){
            inc=true;
        }
    }
    if(inc){
        cout<<"No";
    }else{
        cout<<"Yes";
    }
}
