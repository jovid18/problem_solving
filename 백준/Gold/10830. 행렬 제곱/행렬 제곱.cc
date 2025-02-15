#include <iostream>
#include <vector>
using namespace std;

using MATRIX=vector<vector<int>>;
MATRIX matrix;
int N;

MATRIX multiply(MATRIX A,MATRIX B){
	MATRIX C=A;
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			int sum=0;
			for(int k=0;k<N;++k){
				sum+=A[i][k]*B[k][j]%1000;
			}
			C[i][j]=sum%1000;
		}
	}
	return C;
}

unsigned long long B;

MATRIX  power(MATRIX &a,unsigned long long b){
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
	cin>>N>>B;
	matrix.resize(N);	
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			int num;
			cin>>num;
			 matrix[i].push_back(num%1000);
		}
	}
	MATRIX answer=power(matrix,B);
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			cout<<answer[i][j]<<" ";
		}
		cout<<endl;
	}
}