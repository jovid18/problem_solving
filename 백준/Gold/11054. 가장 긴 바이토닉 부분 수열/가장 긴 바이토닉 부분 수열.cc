#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int N;
vector<int> Sample;
vector<int> Reverse;
void Length(vector<int> &sequence ){
	vector<int> A(1+N,0);
	copy(sequence.begin(),sequence.end(),A.begin()+1);
	vector<int> D(1,0);
	for(int i=1;i<=N;++i){
		int count=0;
		for(int j=0;j<i;++j){
			if(A[j]<A[i]){
				count=max(count,D[j]+1);
			}
		}
		D.push_back(count);
	}
	sequence[0]=D[1];
	for(int i=1;i<N;++i){
		sequence[i]=max(sequence[i-1],D[i+1]);
	}
	
}
int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>N;
	Sample.resize(N);
	Reverse.resize(N);
	for(int i=0;i<N;++i){
		cin>>Sample[i];
	}
	copy(Sample.rbegin(),Sample.rend(),Reverse.begin());
	Length(Sample);
	Length(Reverse);
	int MAX=0;
	for(int i=0;i<N;++i){
		MAX=max(MAX,Sample[i]+Reverse[N-1-i]-1);
	}
	cout<<MAX;
}