#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
using ll=long long;
int N;
vector<int> V;
int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>N;
	V.resize(N);
	for(int i=0;i<N;++i){
		cin>>V[i];
	}
	sort(V.begin(),V.end(),greater<>());
	if(N==1){
		cout<<V[0];
	}else if(N==2){
		cout<<V[0]+V[1]-1;
	}else{
		if(N%3==0){
			cout<<V[0]+V[N/3]+V[2*N/3]-3;
		}else if(N%3==1){
			cout<<V[0]+V[N/3+1]+V[2*N/3+1]-3;
		}else{
			cout<<V[0]+V[N/3+1]+V[2*N/3+1]-3;
		}
	}
}