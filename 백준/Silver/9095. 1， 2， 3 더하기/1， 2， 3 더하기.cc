#include <iostream>
#include <vector>
using namespace std;

int main(){
	int N;
	cin>>N;
	vector<int> cell(12);
	cell[0]=0;
	cell[1]=1;
	cell[2]=2;
	cell[3]=4;
	for(int i=4;i<=11;++i){
		cell[i]=cell[i-1]+cell[i-2]+cell[i-3];
	}
	for(int i=0;i<N;++i){
		int a;
		cin>>a;
		cout<<cell[a]<<endl;
	}
}