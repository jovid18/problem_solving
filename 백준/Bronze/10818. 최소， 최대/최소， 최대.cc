#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int N;
	cin>>N;
	vector<int> num;
	for(int i=0;i<N;++i){
		int a;
		cin>>a;
		num.push_back(a);
	}
	sort(num.begin(),num.end());
	cout<<num[0]<<" "<<num[N-1];
}