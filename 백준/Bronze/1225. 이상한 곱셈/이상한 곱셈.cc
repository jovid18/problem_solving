#include <iostream>
#include <string>
using namespace std;

int main(){

	string A;
	string B;
	cin>>A>>B;
	int a=A.length();
	int b=B.length();
	unsigned long long int asum=0;
	unsigned long long int bsum=0;
	for(int i=0;i<a;i++){
		int anum=A[i]-'0';
		asum+=anum;
	}
	
	for(int j=0;j<b;j++){
		int bnum=B[j]-'0';
		bsum+=bnum;
	}
	unsigned long long int c=asum*bsum;
	cout<<c<<endl;
	
	return 0;
}