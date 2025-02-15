#include <iostream>
using namespace std;

int main(){
	int N,M;
	cin>>N>>M;
	int matrix[N][M];
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			int x;
			cin>>x;
			matrix[i][j]=x;
		}
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			int x;
			cin>>x;
			matrix[i][j]+=x;
		}
	}
	
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}