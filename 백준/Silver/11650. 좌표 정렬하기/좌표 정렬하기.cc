using namespace  std;

#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>



int main(){
	ios_base :: sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
	int N;
	cin>>N;
	vector<pair<int,int>> point;
	for(int i=0;i<N;++i){
		int a,b;
		cin>>a>>b;
		point.push_back(pair<int,int> (a,b));
	}
	sort(point.begin(),point.end());
	for(auto e: point){
		cout<<e.first<<" "<<e.second<<"\n";
	}
}