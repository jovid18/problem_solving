#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
using namespace std;
vector<int> V;
vector<int> C;
int N;
int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>N;
	int before;
	int now;
	int ans=0;
	V.resize(N);
	for(int i=0;i<N;++i){
		cin>>V[i];
	}
	for(int i=1;i<N;++i){
		int siz=C.size();
		if(V[i]>V[i-1]){
			if(siz>=1&&C[siz-1]>0){
				C[siz-1]++;
			}else{
				C.push_back(1);
			}
		}else if(V[i]<V[i-1]){
			if(siz>=1&&C[siz-1]<0){
				C[siz-1]--;
			}else{
				C.push_back(-1);
			}
		}
	}
	int a=0;
	for(auto e: C){
		a=max(a,abs(e));
	}
	cout<<a+1;
}