#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector<int> S;
vector<bool> P;
int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>N;
	S.resize(N);
	P.resize(N);
	for(int i=0;i<N;++i){
		cin>>S[i];
	}
	sort(S.begin(),S.end());
	if(S[0]==S[1]){
		cout<<"No";
		return 0;
	}
	bool check=false;
	int an,bn,da,db=-1,li=-1;
	da=S[1]-S[0];
	an=S[0];
	for(int i=1;i<N;++i){
		if(S[i]-an==da){
			P[i]=true;
			an=S[i];
			li=i;
		}
	}
	auto Pcopy=P;
	for(int i=1;i<N;++i){
		if(P[i]) continue;
		if(db==-1){
			db=S[i]-S[0];
			bn=S[i];
			P[i]=true;
		}else{
			if(S[i]-bn==db){
				bn=S[i];
				P[i]=true;
			}else{
				check=true;
				break;
			}
		}
	}
	if(!check){
		cout<<"Yes";
		return 0;
	}
	P=Pcopy;
	P[li]=false;
	db=-1;
	bn=-1;
	check=false;
	for(int i=1;i<N;++i){
		if(P[i]) continue;
		if(db==-1){
			db=S[i]-S[0];
			bn=S[i];
			P[i]=true;
		}else{
			if(S[i]-bn==db){
				bn=S[i];
				P[i]=true;
			}else{
				check=true;
				break;
			}
		}
	}
	if(!check){
		cout<<"Yes";
	}else{
		cout<<"No";
	}
	
}