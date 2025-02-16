#include <iostream>
#include <vector>
using namespace std;

int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int T;
	cin>>T;
	for(int i=0;i<T;++i){
		int N;
		cin>>N;
		vector<vector<int>> sticker(2,vector<int> (N,0));
		for(int j=0;j<N;++j){
			cin>>sticker[0][j];
		}
		for(int j=0;j<N;++j){
			cin>>sticker[1][j];
		}
		if(N>=2){
			sticker[0][1]+=sticker[1][0];
			sticker[1][1]+=sticker[0][0];
		}
		if(N>2){
			for(int i=2;i<N;++i){
				sticker[0][i]+=max(sticker[1][i-2],sticker[1][i-1]);
				sticker[1][i]+=max(sticker[0][i-2],sticker[0][i-1]);
			}
		}
		cout<<max(sticker[0][N-1],sticker[1][N-1])<<endl;
	}
}