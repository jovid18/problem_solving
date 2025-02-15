#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<string>
using namespace std;

int main(){
	int N,M;
	cin>>N>>M;
	set<string> l;
	set<string> s;
	for(int i=0;i<N;++i){
		string a;
		cin>>a;
		l.insert(a);
	}
	for(int i=0;i<M;++i){
		string a;
		cin>>a;
		s.insert(a);
	}
	set<string> ls;
	set_intersection(begin(l),end(l),begin(s),end(s),inserter(ls,begin(ls)));
	
	cout<<ls.size()<<endl;
	for(auto e: ls){
		cout<<e<<endl;
	}
	
}