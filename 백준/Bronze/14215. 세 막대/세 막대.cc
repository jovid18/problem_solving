#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
const double pi = 3.14159265358979;
vector<int> L(3,0);
int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	for(int i=0;i<3;++i){
		cin>>L[i];
	}
	sort(L.begin(),L.end());
	cout<<L[0]+L[1]+min(L[2],L[0]+L[1]-1);
}