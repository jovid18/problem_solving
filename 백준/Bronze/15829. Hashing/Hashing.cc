#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int N,M=31,MOD=1234567891;
long long ans;
string S; 
int main(){
	cin>>N>>S;
	reverse(S.begin(),S.end());
	for(int i=0;i<N;++i){
		ans*=M;
		long long x=S[i]-'a'+1;
		ans+=x;
		ans%=MOD;
	}
	cout<<ans;
}