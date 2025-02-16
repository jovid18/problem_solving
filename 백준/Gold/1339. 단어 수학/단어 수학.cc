#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int N;
int C[26];
int cnt=1;
vector<int> T(10);
string S;
int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>N;
	while(N--){
		cin>>S;
		for(int i=0;i<S.size();++i){
			int num=S[i]-'A';
			if(C[num]==0){
				C[num]=cnt;
				cnt++;
			}
			T[C[num]-1]+=pow(10,S.size()-i-1);
		}
	}
	int ans=0;
	sort(T.begin(),T.end());
	for(int i=0;i<10;++i){
		ans+=T[i]*i;
	}
	cout<<ans;
}