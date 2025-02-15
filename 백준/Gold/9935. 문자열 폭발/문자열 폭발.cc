#include <iostream>
#include <string>
#include <stack>;
using namespace std;
stack<char> answer;
string sentence;
int main(){
	cin>>sentence;
	string bomb;
	cin>>bomb;
	for(int i=0;i<sentence.size();++i){
		stack <char> bin;
		answer.push(sentence[i]);
		if(answer.top()==bomb[bomb.size()-1]){
			for(int j=bomb.size()-1;j>=0&&!answer.empty();--j){
				char a=answer.top();
				if(a==bomb[j]){
					answer.pop();
					bin.push(a);
				}else{
					break;
				}
			}
			if(bin.size()==bomb.size()){
				continue;
			}else{
				while(!bin.empty()){
				char a=bin.top();
				bin.pop();
				answer.push(a);
				}
			}
		}
	}
	if(answer.empty()){
		cout<<"FRULA";
	}else{
	string result;
	result.resize(answer.size());
	for(int i=answer.size()-1;i>=0;--i){
		result[i]=answer.top();
		answer.pop();
	}
	cout<<result;
	}
		
}