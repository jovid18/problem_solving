#include <bits/stdc++.h>
using namespace std;
#define int long long
int A,B,D;
int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>A>>B>>D;
    cout<<A<<" ";
    while(A!=B){
        A+=D;
        cout<<A<<" ";
    }
}