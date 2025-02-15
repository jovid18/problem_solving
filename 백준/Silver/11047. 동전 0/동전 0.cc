#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	int N,M;
	cin>>N>>M;
	vector<int> coin(N);
	for(int i=0;i<N;++i){
		cin>>coin[i];
	}
	int count=0;
	while(M!=0){
		auto iter=upper_bound(coin.begin(),coin.end(),M);
		iter--;
		if(M==1){
			M=0;
			count++;
		}else{
			M-=*iter;
			count++;
		}
		
	}
	cout<<count;
}