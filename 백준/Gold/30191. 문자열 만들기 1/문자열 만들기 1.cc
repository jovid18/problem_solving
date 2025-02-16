#include <bits/stdc++.h>
using namespace std;
string str,ans;
int N;
stack<pair<char,int>> ST;
bool sf[1000000];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    cin>>N>>str;
    cout<<3*N/2<<'\n';
    for(int i=N-1;i>=0;--i){
        if(!ST.empty()&&ST.top().first!=str[i]){
            sf[ST.top().second]=1;
            ST.pop();
        }else ST.push({str[i],i});
    }
    for(int i=N-1;i>=0;--i){
        if(sf[i]){
            if(str[i]=='S') cout<<"UN";
            else cout<<"SN";
        }else cout<<'N';
    }
}