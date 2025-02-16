#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <list>
using namespace std;

bool primecheck(int num){
	if(num==1){
		return false;
	}
	for(int i=2;i*i<=num;++i){
		if(num%i==0)
			return false;
	}
	return true;
}

int main(){
	int N;
	cin>>N;
	vector<vector<int>> primelist(N+1);
	for(int i=1;i<=N;++i){
		if(i==1){
			for(int j=1;j<=9;j++){
				if(primecheck(j)){
					primelist[i].push_back(j);
				}
			}
		}else{
			for(auto iter=primelist[i-1].begin();iter!=primelist[i-1].end();iter++){
				for(int j=1;j<=9;++j){
					if(primecheck(10*(*iter)+j)){
						primelist[i].push_back(10*(*iter)+j);
					}
				}
			}

			
		}
	}
	for(auto x: primelist[N]){
		cout<<x<<endl;
	}	
}
