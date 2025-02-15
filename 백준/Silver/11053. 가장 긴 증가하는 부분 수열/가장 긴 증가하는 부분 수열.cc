#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int N;
	cin>>N;
	vector<int> A(N+1);
	vector<int> D(N+1);
	for(int i=1;i<=N;++i){
		cin>>A[i];
	}
	
	for(int i=1;i<=N;++i){
		int d=0;
		for(int j=0;j<i;++j){
			if(A[j]<A[i]){
				if(d<D[j]){
					d=D[j];
				}
			}
		}
		D[i]=d+1;
	}
	cout<<*max_element(D.begin(), D.end());
}
