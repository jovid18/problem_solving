#include <iostream> 
#include <algorithm>
#include <cstring>
#include <vector>
#include <bitset>
using namespace std;
const int MAX=100000;
int M,K;
int DP[MAX];
vector<int> P;
string str;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>M;
	cin>>K;
	while(K--){
		int a;
		cin>>a;
		P.push_back(a);
	}
	DP[0]=0;
	str="0";
	for(int i=1;i<MAX;++i){
		bitset<31> mex;
		for(auto e:P){
			if(i<e) break;
			mex[DP[i-e]]=1;
		}
		while(mex[DP[i]]) DP[i]++;
		if(i<5000){
			int j=DP[i];
			char s=j+'0';
			str+=s;
		}
	}
	if(M<MAX){
		int ans=0;
		for(int i=1;i<=M;++i){
			if(DP[i]==0) {
				ans++;
			}
		}
		cout<<ans;
		return 0;
	}
	int T=2;
	for(;;++T){
		bool a=false;
		bool b=false;
		for(int i=0;i+2*T-1<5000;++i){
			if(!a&&str.compare(i,T,str,i+T,T)==0){
				a=true;
			}
			if(a){
				if(str.compare(i,T,str,i+T,T)!=0){
					b=true;
					break;
				}
			}
		}
		if(a&&!b) break;
	};
	int ans=0;
	for(int i=1;i<MAX;++i){
		if(DP[i]==0) ans++;
	}
	int ans2=0;
	for(int i=5001;i<=5000+T;++i){
		if(DP[i]==0) ans2++;
	}
	int repeat=(M-MAX+1)/T;
	ans+=repeat*ans2;
	if((M-MAX+1)%T==0){
		cout<<ans;
		return 0;
	}
	if(MAX%T<=M%T){
		for(int i=2*T+(MAX%T);i<=2*T+(M%T);++i){
			if(DP[i]==0) ans++;
		}
	}else{
		for(int i=2*T+(MAX%T);i<=3*T+M%T;++i){
			if(DP[i]==0) ans++;
		}
	}
	cout<<ans;
}