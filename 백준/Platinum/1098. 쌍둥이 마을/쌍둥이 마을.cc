#include <iostream>

#include <vector>

#include <cmath>

#include <bitset>

using namespace std;

vector<vector<pair<int,int>>> DP(1<<20,vector<pair<int,int>>(10,{-1,0}));

struct state{

	int Condition;	int Pair;

	int Distance;

};

vector<state> S[10];

int dist(pair<int,int> A,pair<int,int>B){

	return abs(A.first-B.first)+abs(A.second-B.second);

}

int R[10][10];

int N,P,D;

pair<int,int> V[10];

pair<int,int> dfs(int s,int count,pair<int,int> pnow){

	if(count==N) return {pnow.first,pnow.second};

	if(DP[s][count].first!=-1){

		return {DP[s][count].first+pnow.first,DP[s][count].second+pnow.second};

	}

	int p=0,d=0;

	for(auto e:S[count]){

		int cp=(s>>2*count)&3;

		if(cp<e.Pair) continue;

		auto copy=s;

		cp-=e.Pair;

		copy &= ~(1<<2*count);

		copy &= ~(1<<2*count+1);

		if(cp==0){

		}else if(cp==1){

			copy|=(1<<2*count);

		}else if(cp==2){

			copy|=(1<<2*count+1);

		}

		bool check=false;

		for(int i=0;i<N;++i){

			if(e.Condition&(1<<i)){

				int cpi=(copy>>2*i)&3;

				if(cpi==0){

					check=true;

					break;

				}

				cpi--;

				copy &= ~(1<<2*i);

				copy &= ~(1<<2*i+1);

				if(cpi==0){

				}else if(cpi==1){

					copy|=(1<<2*i);

				}else if(cpi==2){

					copy|=(1<<2*i+1);

				}

			}

		}

		if(check) continue;

		auto result=dfs(copy,count+1,{pnow.first+e.Pair,pnow.second+e.Distance});

		if(p<result.first){

			p=result.first;

			d=result.second;

		}else if(p==result.first){

			d=min(d,result.second);

		}

	}

	DP[s][count]={p-pnow.first,d-pnow.second};

	return {p,d};

}

int main(){

	cin>>N;

	for(int i=0;i<N;++i){

		cin>>V[i].first>>V[i].second;

	}

	cin>>P>>D;

	for(int i=0;i<N;++i){

		for(int j=i+1;j<N;++j){

			int d=dist(V[i],V[j]);

			if(d<D) continue;

			R[i][j]=d;

			R[j][i]=d;

		}

	}

	for(int s=0;s<(1<<N);++s){

		if(__builtin_popcount(s)>P) continue;

		for(int i=0;i<N;++i){

			if(s&(1<<i)) continue;

			bool check=true;

			int p=0,d=0;

			for(int j=0;j<N;++j){

				if(!(s&(1<<j))) continue;

				if(R[i][j]==0||(j<i&&(s&(1<<j)))){

					check=false;

					break;

				}

				p++;

				d+=R[i][j];

			}

			if(check) S[i].push_back({s,p,d});

		}

	}

	int bitmask=0;

	for(int i=0;i<N;++i){

		bitmask+=P*(1<<2*i);

	}

	auto ans=dfs(bitmask,0,{0,0});

	cout<<ans.first<<" "<<ans.second;

}