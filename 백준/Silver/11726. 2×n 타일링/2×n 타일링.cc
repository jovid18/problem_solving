#include <iostream>
#include <vector>

using namespace std;

int main(){
	vector<int> pibo(1001);
	pibo[1]=1;
	pibo[2]=2;
	for(int i=3;i<1001;++i){
		pibo[i]=(pibo[i-1]+pibo[i-2])%10007;
	}
	int n;
	cin>>n;
	cout<<pibo[n];
}
