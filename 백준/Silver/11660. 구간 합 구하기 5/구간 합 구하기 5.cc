#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> cell(1024,vector<int>(1024,0));
vector<vector<int>> sum(1025,vector<int>(1025,0));
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL); 
	cout.tie(NULL);
	int N,M;
	cin>>N>>M;
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			cin>>cell[i][j];
		}
	}
	for(int i=1;i<=N;++i){
		for(int j=1;j<=N;++j){
			sum[i][j]=-sum[i-1][j-1]+sum[i-1][j]+sum[i][j-1]+cell[i-1][j-1];
		}
	}
	for(int i=0;i<M;++i){
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		cout<<sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1]<<'\n';
	}
}