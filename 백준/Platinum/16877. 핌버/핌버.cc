#include <iostream> 
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
const int MAX=3000001;
int N;
int DP[MAX+1];
int P[35];
vector<bool> visited;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	P[0]=1;
	P[1]=2;
	for(int i=2;i<35;++i){
		P[i]=P[i-1]+P[i-2];
	}
	for(int i=1;i<MAX;++i){
		visited.assign(35,false);
		for(int j=0;;++j){
			if(i<P[j]) break;
			visited[DP[i-P[j]]]=true;
		}
		for(int j=0;j<35;++j){
			if(!visited[j]){
				DP[i]=j;
				break;
			}
		}
	}
	int p=0;
	cin>>N;
	while(N--){
		int x;
		cin>>x;
		p^=(DP[x]);
	}
	if(p==0){
		cout<<"cubelover";
	}else{
		cout<<"koosaga";
	}
}
