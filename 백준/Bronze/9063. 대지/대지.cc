#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
const double pi = 3.14159265358979;
vector<long long> X,Y;
int N;
int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>N;
	X.resize(N);
	Y.resize(N);
	for(int i=0;i<N;++i){
		cin>>X[i]>>Y[i];
	}
	sort(X.begin(),X.end());
	sort(Y.begin(),Y.end());
	cout<<(X[N-1]-X[0])*(Y[N-1]-Y[0]);
}