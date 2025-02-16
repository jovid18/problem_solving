#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
int N;
string S;
int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int ans=0;
	while(cin>>S){
		if(S[0]=='['){
			ans+=8;
		}else if(S[0]==']'){
			continue;
		}else if(S.size()<=17&&'0'<=S[0]&&S[0]<='9'){
			ans+=8;
		}else{
			ans+=12+S.size();
		}
	}
	cout<<ans;
}