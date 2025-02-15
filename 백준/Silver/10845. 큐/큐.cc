#include <iostream>
#include <queue>
#include <string>
using namespace std;
queue<int> Q;
int N,X;
string com;
int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>N;
	while(N--){
		cin>>com;
		if(com=="push"){
			cin>>X;
			Q.push(X);
		}else if(com=="pop"){
			if(Q.empty()){
				cout<<-1<<'\n';
			}else{
				cout<<Q.front()<<'\n';
				Q.pop();
			}
		}else if(com=="size"){
			cout<<Q.size()<<'\n';
		}else if(com=="empty"){
			cout<<Q.empty()<<'\n';
		}else if(com=="front"){
			if(Q.empty()){
				cout<<-1<<'\n';
			}else{
				cout<<Q.front()<<'\n';
			}
		}else{
			if(Q.empty()){
				cout<<-1<<'\n';
			}else{
				cout<<Q.back()<<'\n';
			}
		}
	}
}