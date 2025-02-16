#include <iostream>
#include <string>
#include <vector>
using namespace std;
string O;
vector<char> S;
vector<int> A;
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>O;
	for(int i=0;i<O.size();++i){
		S.push_back('#');
		S.push_back(O[i]);
	}
	S.push_back('#');
	int s=S.size();
	A.assign(S.size(),0);
	int r=-1,p=-1;
	long long ans=0;
	for(int i=0;i<A.size();++i){
		if(i<=r){
			A[i]=min(r-i,A[2*p-i]);
		}
		while(i-A[i]-1>=0&&i+A[i]+1<S.size()&&S[i-A[i]-1]==S[i+A[i]+1]){
			A[i]++;	
		}
		if(r<i+A[i]){
			r=i+A[i];
			p=i;	
		}
		ans+=(A[i]+1)/2;
	}
	cout<<ans;
}
