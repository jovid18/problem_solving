#include <iostream>
#include <set>
using namespace std;
long long N;
int main(){
	cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
	cin>>N;
	if(N%5==0||N%5==2){
		cout<<"CY";
	}else{
		cout<<"SK";
	}
}
