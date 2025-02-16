#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N,M;
vector<int> soldier;
vector<int> work;
int main(){
	cin>>N>>M;
	soldier.resize(N);
	work.resize(M);
	for(int i=0;i<N;++i){
		cin>>soldier[i];
	}
	for(int i=0;i<M;++i){
		cin>>work[i];
	}
	sort(soldier.begin(),soldier.end());
	sort(work.begin(),work.end());
	int count=0;
	int need=0;
	for(int i=0;i<M;++i){
		need++;
		int a= lower_bound(soldier.begin(), soldier.end(), need) - soldier.begin();
		for(int j=a;j<a+work[i]&&j<N;++j){
			soldier[j]=0;
		}

		if(N-a<work[i]){
			count++;
			break;
		}
		
	}
	if(count==1){
		cout<<"NO";
	}else{
		cout<<"YES";
	}
}