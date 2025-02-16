#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector<int> prime(4000001,0);
void isprime(){
	for (int i=2; i*i<=4000000;i++){
		if (prime[i] == 0)
            continue;
        for(int j=i*i;j<=4000000;j+=i)
            prime[j] = 0;
    }
}

int main(){
	cin>>N;
	for(int i=2;i<=4000000;++i){ 
		prime[i]=i;
	}
	isprime();
	sort(prime.begin(),prime.end());
	prime.erase(unique(prime.begin(),prime.end()),prime.end());
	prime.erase(prime.begin());
	int count=0;
	int sum=0;
	auto start=prime.begin();
	auto finish=prime.begin();
	while(start!=prime.end()){
		if(finish==prime.end()){
			if(sum==N){
				count++;
			}
			sum-=*start;
			start++;
			continue;
		}
		
		if(sum<N){
			sum+=*finish;
			finish++;
		}else{
			if(sum==N){
				count++;
			}
			sum-=*start;
			start++;
		}
	}
	cout<<count;	
}