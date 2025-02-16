#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b){
	 while (b != 0)
    {
        int tmp = a;
        a = b;
        b = tmp%b;
    }
	return a;
}

int main(){
	int T;
	cin>>T;
	for(int i=0;i<T;++i){
		int N;
		cin>>N;
		vector<int> num(N);
		for(int j=0;j<N;++j){
			int a;
			cin>>a;	
			num[j]=a;
		}
		int first=num[0];
		for(int j=0;j<N;++j){
			num[j]-=first;
		}
		int a=0;
		for(int j=0;j<N;++j){
			a=gcd(a,num[j]);
		}
		if(a==0){
			cout<<"INFINITY"<<endl;
		}else if(a>0){
			cout<<a<<endl;
		}else{
			cout<<-a<<endl;
		}
	}
}