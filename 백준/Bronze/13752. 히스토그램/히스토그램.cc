#include <iostream>
using namespace std;
int N,M;
int main(){
	cin>>N;
	for(int i=0;i<N;++i){
		cin>>M;
		for(int j=0;j<M;++j){
			cout<<'=';
		}
		cout<<'\n';
	}
}