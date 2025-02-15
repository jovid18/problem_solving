#include <iostream>
#include <deque>
using namespace std;
int T,N;
bool mode,error;
string p,d;
deque<int> A;
void print(){
	cout<<'[';
	while(!A.empty()){
		if(mode){
			cout<<A.back();
			A.pop_back();
		}else{
			cout<<A.front();
			A.pop_front();
		}
		if(!A.empty()) cout<<',';
		else break;
	}
	cout<<']'<<'\n';
}
int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>T;
	while(T--){
		cin>>p>>N>>d;
		mode=0;
		while(!A.empty()){
			A.pop_front();
		}
		int num=0;
		for(int i=1;i<d.size();++i){
			if(d[i]==','||d[i]==']'){
				A.push_back(num);
				num=0;
			}else{
				num*=10;
				num+=d[i]-'0';
			}
		}
		if(!N) A.pop_front(); 
		for(int i=0;i<p.size();++i){
			if(p[i]=='R') mode^=1;
			else{
				if(A.empty()){
					error=true;
					continue;
				}
				if(mode) A.pop_back();
				else A.pop_front();
			}
		}
		if(error){
			error^=1;
			cout<<"error"<<'\n';
			continue;
		}
		print();
	}
}