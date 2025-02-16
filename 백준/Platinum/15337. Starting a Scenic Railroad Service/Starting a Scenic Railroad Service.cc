#include <iostream>
#include <vector>
using namespace std;
using pii=pair<int,int>;
int N,now,p1,p2;
int imos[100001],fmore[100001],sless[100001];
vector<pii> V;
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	V.resize(N);
	for(int i=0;i<N;++i){
		cin>>V[i].first>>V[i].second;
		fmore[V[i].first]++;
		sless[V[i].second]++;
		imos[V[i].first]++;
		imos[V[i].second]--;
	}
	for(int i=0;i<=100000;++i){
		now+=sless[i];
		sless[i]=now;
	}
	now=0;
	for(int i=100000;i>=0;--i){ 
		now+=fmore[i];
		fmore[i]=now;
	}
	for(int i=0;i<N;++i){
		p1=max(p1,N-fmore[V[i].second]-sless[V[i].first]);
	}
	now=0;
	for(int i=0;i<=100000;++i){
		now+=imos[i];
		imos[i]=now;
		p2=max(p2,imos[i]);
	}
	cout<<p1<<" "<<p2;
}