#include <bits/stdc++.h>
using namespace std;
int N;
int A[1001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    A[0]=1;
    A[1]=1;
    for(int i=2;i<=1000;++i){
        set<int> S;
        for(int j=1;i-2*j>=0;++j){
            int f=A[i-2*j];
            int s=A[i-j];
            S.insert(2*s-f);
        }
        for(int j=1;;++j){
            if(S.find(j)==S.end()){
                A[i]=j;
                break;
            }
        }
    }
    cin>>N;
    cout<<A[N];
}