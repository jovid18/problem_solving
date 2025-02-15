#include <bits/stdc++.h>
using namespace std;
#define int long long
int N,L;
string s;
vector<int> H;
int32_t main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N>>L;
    while(N--){
        cin>>s; 
        s.erase(unique(s.begin(),s.end()),s.end());
        int black=0;
        for(int i=0;i<s.size();++i){
            if(s[i]=='1') black++;
        }
        H.push_back(black);
    }
    sort(H.begin(),H.end());
    int ans=upper_bound(H.begin(),H.end(),H.back())-lower_bound(H.begin(),H.end(),H.back());
    cout<<H.back()<<" "<<ans;
}
