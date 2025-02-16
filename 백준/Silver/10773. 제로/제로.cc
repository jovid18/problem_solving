#include <iostream>
#include <stack>
using namespace std;
int K;
stack<int> S;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>K;
	while(K--){
		int x;
		cin>>x;
		if(x==0) S.pop();
		else S.push(x);
	}
	int ans=0;
	while(!S.empty()){
		ans+=S.top();
		S.pop();
	}
	cout<<ans;
}