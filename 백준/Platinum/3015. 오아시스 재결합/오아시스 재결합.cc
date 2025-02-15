#include <iostream>
#include <stack>
using namespace std;
stack<pair<int,int>> S;
int main(){
	int T;
	cin>>T;
	long long cnt=0;
	while(T--){
		int now;
		cin>>now;
		if(S.empty()){
			S.push({now,1});
			continue;
		} 
		while(!S.empty()&&S.top().first<now){
			cnt+=S.top().second;
			S.pop();
		}
		if(S.empty()){
			S.push({now,1});
			continue;
		}else{
			if(!S.empty()&&S.top().first==now){
				cnt+=S.top().second;
				if(S.size()>1) cnt++;
				S.top().second++;
			}else{
				cnt++;
				S.push({now,1});
			}
		}
	}
	cout<<cnt;
}