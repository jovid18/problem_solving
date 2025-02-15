#include <iostream>
#include <vector>
using namespace std;

using MATRIX=vector<vector<unsigned long long>>;
MATRIX m={{0,1,1,0,0,0,0,0},{1,0,1,1,0,0,0,0,},{1,1,0,1,1,0,0,0},{0,1,1,0,1,1,0,0,},{0,0,1,1,0,1,1,0},{0,0,0,1,1,0,0,1},{0,0,0,0,1,0,0,1},{0,0,0,0,0,1,1,0}};
MATRIX multiply(MATRIX A,MATRIX B){
	MATRIX C=A;
	for(int i=0;i<8;++i){
		for(int j=0;j<8;++j){
			unsigned long long sum=0;
			for(int k=0;k<8;++k){
				sum+=A[i][k]*B[k][j]%1000000007;
			}
			C[i][j]=sum%1000000007;
		}
	}
	return C;
}
int D;
MATRIX  power(MATRIX &a,int b){
	if(b==1){
		return a;
	}
	if(b%2==0){
		MATRIX c=power(a,b/2);
		return multiply(c,c);
	}else{
		MATRIX c=power(a,(b-1)/2);
		return multiply(multiply(c,c),a);
	}
}

int main(){
	cin>>D;
	MATRIX answer=power(m,D);
	cout<<answer[0][0];
}