#include <iostream>
#include <vector>
using namespace std;
bool A[1000001];
int B[1000001];
vector<int> C;
int N;
int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>N;
	for(int i=0;i<N;++i){
		int x;
		cin>>x;
		A[x]=true;
		C.push_back(x);
	}
	for(int i=1;i<=1000000;++i){
		if(!A[i]) continue;
		for(int j=2;j*i<=1000000;++j){
			if(A[i]&&A[j*i]){
				B[i]++;
				B[i*j]--;
			}
		}
	}
	for(auto e:C){
		if(A[e]) cout<<B[e]<<" ";
	}
}