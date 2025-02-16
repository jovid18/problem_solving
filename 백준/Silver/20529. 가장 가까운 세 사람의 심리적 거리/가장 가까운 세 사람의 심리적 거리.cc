#include <iostream>
#include <vector>
#include <string>
using namespace std;
int T,N;
vector<int> S(15);
vector<int> P;
int toint(string s){
	int ret=0;
	if(s[0]=='E') ret+=8;
	if(s[1]=='N') ret+=4;
	if(s[2]=='T') ret+=2;
	if(s[3]=='P') ret+=1;
	return ret;
}
int dist(int a, int b){
	int x=a^b;
	return __builtin_popcount(x);
}
int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>T;
	while(T--){
		S.assign(16,0);
		P.clear();
		int ans=1e9;
		cin>>N;
		if(N>32) ans=0;
		for(int i=0;i<N;++i){
			string s;
			cin>>s;
			int mbti=toint(s);
			if(S[mbti]==3) ans=0;
			if(S[mbti]<3){
				S[mbti]++;
				P.push_back(mbti);
			}
		}
		if(!ans){ 
			cout<<0<<'\n';
			continue;
		}
		int p=P.size();
		for(int i=0;i<p;++i){
			for(int j=i+1;j<p;++j){
				for(int k=j+1;k<p;++k){
					int now=dist(P[i],P[j]);
					now+=dist(P[j],P[k]);
					now+=dist(P[i],P[k]);
					ans=min(ans,now);
				}
			}
		}
		cout<<ans<<'\n';
	}
}