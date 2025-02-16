#include <iostream>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int N,M;
vector<int> S;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>M;
	if(M>26*N||M<N){
		cout<<'!';
		return 0;
	}
	S.resize(N);
	int idx=0;
	for(;idx<N;++idx){
		if(M>26+(N-idx-1)){
			S[idx]=26;
			M-=26;
		}else{
			break;
		}
	}
	S[idx]=M-(N-idx-1);
	idx++;
	for(;idx<N;++idx){
		S[idx]=1;
	}
	sort(S.begin(),S.end());
	for(auto e:S){
		cout<<(char)(e+64);
	}
}