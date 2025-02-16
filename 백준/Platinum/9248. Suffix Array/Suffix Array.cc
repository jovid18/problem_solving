#include <iostream> 
#include <algorithm>
#include <string>
using namespace std;
const int MAX=600000;
int N;
string str;
int t,G[MAX],TG[MAX],SA[MAX],RSA[MAX],LCP[MAX];
bool comp(int x,int y){
	if(G[x]==G[y]) return G[x+t]<G[y+t];
	return G[x]<G[y];
}
void findSA(){
	t=1;
	N=str.length();
	for(int i=0;i<N;++i){
		SA[i]=i;
		G[i]=str[i]-'a';
	}
	while(t<=N){
		G[N]=-1;
		sort(SA,SA+N,comp);
		TG[SA[0]]=0;
		for(int i=1;i<N;++i){
			if (comp(SA[i-1],SA[i])) TG[SA[i]]=TG[SA[i-1]]+1;
            else TG[SA[i]]=TG[SA[i-1]];
		}
		for(int i=0;i<N;++i){
			G[i]=TG[i];
		}
		t*=2;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>str;
	findSA();
	for(int i=0;i<N;++i){
		RSA[SA[i]]=i;
	}
	int l=0;
	for(int i=0;i<N;++i){
		int k=RSA[i];
		if(k){
			int j=SA[k-1];
			while(str[i+l]==str[j+l]){
				l++;
			}
			LCP[k]=l;
			if(l) l--;
		}
	}
	for(int i=0;i<N;++i){
		cout<<SA[i]+1<<" ";
	}
	cout<<"\nx ";
	for(int i=1;i<N;++i){
		cout<<LCP[i]<<" ";
	}
}