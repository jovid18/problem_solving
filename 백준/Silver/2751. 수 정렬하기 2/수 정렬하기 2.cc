#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
int main(){
	int N;
	scanf("%d",&N);
	vector<int> num;
	int a=0;
	for(int i=0;i<N;++i){
		scanf("%d",&a);
		num.push_back(a);
	}
	sort(num.begin(),num.end());
	for(auto e: num){
		printf("%d\n",e);
	}
	
}