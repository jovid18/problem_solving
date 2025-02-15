#include <iostream>
#include <set>
using namespace std;
multiset<int> ms;
int T,K,N;
char C;
int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>T;
	while(T--){
		ms.clear();
		cin>>K;
		while(K--){
			cin>>C>>N;
			if(C=='I'){
				ms.insert(N);
			}else{
				if(ms.empty()) continue;
				if(N==1) ms.erase(--ms.end());
				else ms.erase(ms.begin());
			}
		}
		if(ms.empty()) cout<<"EMPTY\n";
		else cout<<*(--ms.end())<<" "<<*ms.begin()<<'\n';
	}
}