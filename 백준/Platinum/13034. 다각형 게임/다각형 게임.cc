#include <iostream>
#include <set>
using namespace std;
int DP[1001];
int N;
int main(){
	cin>>N;
	DP[0]=0;
	DP[1]=0;
	DP[2]=1;
	for(int i=3;i<=N;++i){
		set<int> S;
		for(int j=0;j<=(i/2);++j){
			S.insert(DP[j]^DP[i-2-j]);
		}
		for(int j=0;;++j){
			if(S.count(j)==0){
				DP[i]=j;
				break;
			}
		}
	}
	if(DP[N]){
		cout<<1;
	}else{
		cout<<2;
	}
}