#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
struct person{
	int first;
	string second;
};

bool compare(const person& a,const person& b){
	return a.first<b.first;
}

int main(){
	ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
	int N;
	cin>>N;
	person words[N];
	for(int i=0;i<N;++i){
		cin>>words[i].first>>words[i].second;
	}
	stable_sort(words,words+N,compare);
		for(int i=0;i<N;++i){
		cout<<words[i].first<<" "<<words[i].second<<"\n";
	}
}