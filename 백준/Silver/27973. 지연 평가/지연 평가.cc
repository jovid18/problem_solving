#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
using namespace std;
using ll=long long;
ll a=1,b=0,now=1;
int Q;

int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>Q;
	for(int i=0;i<Q;++i){
		long long n,x;
		cin>>n;
		if(n==0){
			cin>>x;
			b+=x;
		}else if(n==1){
			cin>>x;
			a*=x;b*=x;
		}else if(n==2){
			cin>>x;
			now+=x;
		}else{
			cout<<a*now+b<<'\n';
		}
		
	}
}