#include <iostream>
using namespace std;
long long N,n,ans;
int main(){
	cin>>N;
	ans=N;
	n=N;
	for(long long i=2;i*i<=N;++i){
		if(n%i==0){
			ans/=i;
			ans*=(i-1);
			while(n%i==0){
				n/=i;
			}
		}
	}
	if(n!=1){
		ans/=n;
		ans*=(n-1);
	}
	cout<<ans;	
}