#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<queue<int>> S;
vector<bool> F;
vector<int> W;
int flug=0;
int pull=0;
int N,K;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>K;
	S.resize(K+1);
	F.resize(K+1);
	for(int i=0;i<K;++i){
		int a;
		cin>>a;
		W.push_back(a);
		S[a].push(i);
	}	
	for(int i=0;i<K;++i){
		if(F[W[i]]){
			S[W[i]].pop();
		}else{
			if(flug<N){
				F[W[i]]=true;
				S[W[i]].pop();
				flug++;
			}else{
				int maxd=-1,maxj=-1;
				for(int j=1;j<=K;++j){
					if(F[j]){
						if(S[j].empty()){
							maxj=j;
							break;
						}
						if(maxd<S[j].front()){
							maxd=S[j].front();
							maxj=j;
						}
					}
				}
				F[maxj]=false;
				pull++;
				F[W[i]]=true;
				S[W[i]].pop();
			}
		}
	}
	cout<<pull;
}