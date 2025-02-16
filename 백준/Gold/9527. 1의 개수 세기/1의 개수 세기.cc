#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector<long long> presum(55);
long long a,b;
long long findone(long long x){
	if(x<=0){
		return 0;
	}else{
		int i=54;
		while(pow(2,i)-1>x){
			i--;
		}
		long long y=pow(2,i)-1;
		return presum[i]+x-y+findone(x-y-1);
	}
	
} 
int main(){
	cin>>a>>b;
	presum[0]=0;
	for(int i=1;i<55;++i){
		presum[i]=pow((long long) 2,i-1)+2*presum[i-1];
	}
	cout<<findone(b)-findone(a-1);
}