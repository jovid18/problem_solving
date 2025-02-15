#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long N;
vector<long long> A,B;
long long a,b,c,d;
void make(){
	A[d]=A[a]+B[c]-B[b];
	a=(a+3)%N;
	b=(b+3)%N;
	c=(c+3)%N;
	d=(d+3)%N;
}
void sola(){
	A[0]=0;
	for(int i=0;i<N;++i){
		make();
	}
	int rem=(B[1]-A[0]-A[1]-A[2])/3;
	for(int i=0;i<N;++i){
		A[i]+=rem;
	}
}
void solb(){
	A[0]=0,A[1]=0,A[2]=0;
	for(int i=0;i<(N/3)-1;++i){
		make();
	}
	a=1,b=(a+1)%N,c=(a+2)%N,d=(a+3)%N;
	for(int i=0;i<(N/3)-1;++i){
		make();
	}
	a=2,b=(a+1)%N,c=(a+2)%N,d=(a+3)%N;
	for(int i=0;i<(N/3)-1;++i){
		make();
	}
	for(int i=0;i<3;++i){
		int idx=min_element(A.begin(),A.end())-A.begin();
		int min=*min_element(A.begin(),A.end());
		if(min>0) break;
		idx%=3;
		min=-min+1;
		for(;idx<N;idx+=3){
			A[idx]+=min;
		}
	}
	int rem=B[1]-A[1]-A[2]-A[0];
	if(rem>0){
		for(int i=1;i<N;i+=3){
			A[i]+=rem;
		}
	}
}
int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>N;
	a=0,b=(a+1)%N,c=(a+2)%N,d=(a+3)%N;
	A.resize(N);
	B.resize(N);
	for(int i=0;i<N;++i){
		cin>>B[i];
	}
	if(N%3!=0){
		sola();
	}else{
		solb();
	}
	for(auto e:A){
		cout<<e<<'\n';
	}
}