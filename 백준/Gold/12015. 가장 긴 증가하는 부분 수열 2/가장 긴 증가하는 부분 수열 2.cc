#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int N;
	cin>>N;
	vector<int> A(N+1);
	vector<int> D(N+1);
	vector<int> A_;
	vector<int> D_;
	for(int i=1;i<=N;++i){
		cin>>A[i];
	}
	A_.push_back(0);
	D_.push_back(0);
	for(int i=1;i<=N;++i){
		auto iter=lower_bound(A_.begin(),A_.end(), A[i]);
		if(iter==A_.end()){
			A_.push_back(A[i]);
			D[i]=D_[D_.size()-1]+1;
			D_.push_back(D_.size());
		}else{
			int index=iter-A_.begin();
			D[i]=D_[index];
			A_[index]=A[i];
		}
	}
	cout<<*max_element(D.begin(), D.end());
}
