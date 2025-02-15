#include <bits/stdc++.h>
using namespace std;
int N;
string S;
int A[1000000];
void manachers(string S)
{
    int N=S.size();
    int r =0 ,p=0;
    for(int i=0;i<N;i++)
    {
        if (i<=r)A[i]=min(A[2*p-i],r-i);
        else A[i] = 0;
        while(i-A[i]-1>=0&&i+A[i]+1<N&&S[i-A[i]-1]==S[i+A[i]+1])A[i]++;
        if (r<i+A[i])
        {
            r=i+A[i];
            p=i;
        }
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> S;
    reverse(S.begin(), S.end());
    string R;
    R.resize(2 * N + 1);
    for (int i = 0; i < N; ++i) R[2 * i + 1] = S[i];
    for (int i = 0; i <= 2 * N; i += 2) R[i] = '*';
    manachers(R);
    int maxr=-1;
    for(int i=1;i<=2*N;++i){
        if(i==A[i]) maxr=max(maxr,A[i]);
    }
    cout<<N-maxr;
}