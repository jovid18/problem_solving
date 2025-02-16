#include <cstdio>
#include <cmath>
using namespace std;

int main(){
	int M,N;
	scanf("%d %d",&M,&N);
	bool prime[N+1];
	for(int i=2;i<=N;++i){
		prime[i]=true;
	}
	for(int i=2;i<sqrt(N+1)+1;++i){
		if(prime[i]==true){
			for(int j=i+1;j<N+1;++j){
				if(j%i==0){
					prime[j]=false;	
				}
			}
		}
	}
	for(int i=M;i<=N;++i){
		if(prime[i]){
			printf("%d\n",i);
		}
	}
}