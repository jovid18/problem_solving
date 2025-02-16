#include <iostream>
using namespace std;
int N,X,S;
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>X;
	for(int i=0;i<N;++i){
		cin>>S;
		if(S<X) cout<<S<<" ";
	}
}
