#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
	int pascal[31][31]={0};
	pascal[0][0]=1;
	for(int i=0;i<=30;i++){
		pascal[i][0]=1;
	}
	for(int i=1;i<=30;++i){
		pascal[i][i]=1;
	}
	for(int i=2;i<=30;i++){
		for(int j=1;j<i;j++){
			pascal[i][j]=pascal[i-1][j-1]+pascal[i-1][j];
		}
	}
	int N;
	cin>>N;
	for(int i=1;i<=N;i++){
		int a,b;
		cin>>a>>b;
		cout<<pascal[b][a]<<endl;
	}
	return 0;
	
}