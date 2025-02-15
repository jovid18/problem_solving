#include <bits/stdc++.h>
using namespace std;
#define int long long
int N,M,R;
vector<int> A;
vector<int> B;
int32_t main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N>>M>>R;
    A.resize(N);
    for(int i=0;i<N;++i){
        cin>>A[i];
    }
    B.resize(M);
    for(int i=0;i<M;++i){
        cin>>B[i];
    }
    sort(A.begin(),A.end());
    sort(B.begin(),B.end(),greater<>());
    int ans=-1;
    for(int i=0;i<N;++i){
        for(int j=i+1;j<N;++j){
            int bottom=A[j]-A[i];
            auto height=lower_bound(B.begin(),B.end(),2*R/bottom,greater<>());
            if(height==B.end()) continue;
            ans=max(ans,bottom*(*height));
        }
    }
    cout<<fixed;
    cout.precision(1);
    if(ans==-1){
        cout<<-1;
    }else{
        double x=ans;
        cout<<x/2;
    }
    

}
