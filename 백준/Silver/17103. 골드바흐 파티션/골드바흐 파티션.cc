#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;
const int MAX=1e6+1;
bool prime[MAX];
vector<int> P;
int ans[MAX];
void seive(){
	prime[0] = prime[1] = true;
	for (int i = 2; i < sqrt(MAX); i++){
		if (prime[i] == false){
			for (int j = 2*i; j <= MAX; j += i){
				prime[j] = true;
			}
		}
	}
}
int T;
int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	seive();
	cin>>T;
	while(T--){
		int x,ans=0;
		cin>>x;
		if(x==4){ 
			cout<<1<<'\n';
			continue;
		}
		for(int i=3;2*i<=x;++i){
			if(!prime[i]&&!prime[x-i]) ans++;
		}
		cout<<ans<<'\n';
	}
}
