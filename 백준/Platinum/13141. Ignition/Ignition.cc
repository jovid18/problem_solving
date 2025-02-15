#include <iostream>

#include <vector>

#include <cstring>

using namespace std;

const long double INF= 100000000;

vector<vector<long double>> adj1,adj2,dist;

int N,M;

void FLOYD(){

	for(int i=1;i<=N;++i){		for(int j=1;j<=N;++j){

			if(i==j) dist[i][j]=0;

		}

	}

	for(int k=1;k<=N;k++){

		for(int i=1;i<=N;i++){

			for(int j=1;j<=N;j++){

				dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);

			}

		}

	}

}

int main(){

	ios_base :: sync_with_stdio(false); 

	cin.tie(NULL); 

	cout.tie(NULL);

	cin>>N>>M;

	adj1.assign(N+1,vector<long double>(N+1,INF));

	adj2.assign(N+1,vector<long double>(N+1,0));

	for(int i=0;i<M;++i){

		long double a,b,c;

		cin>>a>>b>>c;

		adj1[a][b]=min(adj1[a][b],c);

		adj1[b][a]=min(adj1[b][a],c);

		adj2[a][b]=max(adj2[a][b],c);

		adj2[b][a]=max(adj2[b][a],c);

	}

	dist=adj1;

	FLOYD();

	long double answer=200000000;

	for(int i=1;i<=N;++i){

		long double subanswer=0;

		for(int j=1;j<=N;++j){

			for(int k=j;k<=N;++k){

				subanswer=max(subanswer,(adj2[j][k]+dist[i][k]+dist[i][j])/2);

			}

		}

		answer=min(answer,subanswer);

	}

	cout<<fixed;

	cout.precision(1);

	cout<<answer;

}