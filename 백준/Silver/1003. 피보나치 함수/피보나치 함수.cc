#include <iostream>
#include <vector>
using namespace std;

int main(){
	vector<int> pibo(41);
	pibo[0]=0;
	pibo[1]=1;
	for(int i=2;i<41;++i){
		pibo[i]=pibo[i-1]+pibo[i-2];
	}
	
	int N;
	cin>>N;
	for(int i=0;i<N;++i){
		int x;
		cin>>x;
		if(x==0){
			cout<<1<<" "<<0<<endl;
		}else{
			cout<<pibo[x-1]<<" "<<pibo[x]<<endl;
		}
	}
}