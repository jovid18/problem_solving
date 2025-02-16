#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    priority_queue<unsigned long long> maxheap;
	int N;
	cin>>N;
	for(int i=0;i<N;++i){
		unsigned long long a;
		cin>>a;
		if(a==0){
			if(maxheap.empty()){
				cout<<0<<'\n';
			}else{
				cout<<maxheap.top()<<'\n';
				maxheap.pop();
			}
		}else{
			maxheap.push(a);
		}
	}

    return 0;
}
