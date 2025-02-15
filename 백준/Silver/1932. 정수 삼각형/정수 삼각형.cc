#include <iostream>
#include <vector>
using namespace std;
using tree=vector<vector<int>>;
tree input(501,vector<int>(501,0));
tree output(501,vector<int>(501,0));
int main(){
	int N;
	cin>>N;
	for(int i=1;i<=N;++i){
		for(int j=1;j<=i;++j){
			cin>>input[i][j];
		}
	}
	output=input;
	for(int i=N-1;i>=1;--i){
		for(int j=1;j<=i;++j){
			output[i][j]+=max(output[i+1][j],output[i+1][j+1]);
		}
	}
	cout<<output[1][1];
	
}