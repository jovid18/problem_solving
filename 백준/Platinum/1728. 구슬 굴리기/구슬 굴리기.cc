#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int N;
	cin>>N;
	vector<vector<int>> marble(N+1);
	for(int i=0;i<=N;i++){
		for(int j=1;j<=N;j++){
			int a;
			cin>>a;
			marble[i].push_back(a);
		}
		sort(marble[i].begin(),marble[i].end());
	}
	vector<int> velocity(N);
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			int v=marble[1][j]-marble[0][i];
			int check=0;
			for(int k=1;k<=N;++k){
				auto iter=lower_bound(marble[k].begin(),marble[k].end(),marble[0][i]+v*k);
				if(*iter!=marble[0][i]+v*k){
					break;
				}
				check++;
			}
			if(check==N){
				velocity[i]=v;
				break;
			}
		}
	}
	for(int i=0;i<N;++i){
		cout<<marble[0][i]<<" "<<velocity[i]<<endl;
	}
}