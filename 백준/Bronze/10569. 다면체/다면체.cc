#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
const double pi = 3.14159265358979;
int N;
int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>N;
	int v,e;
	for(int i=0;i<N;++i){
		cin>>v>>e;
		cout<<(2+e-v)<<'\n';
	}
}