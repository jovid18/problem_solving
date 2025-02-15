#include <iostream>
#include <vector>
#include <string>
using namespace std;
const int MAX=10002;

int stack[MAX];
int top=0;

bool empty(){
	if(top==0){
		cout<<1<<endl;
		return true;
	}else{
		cout<<0<<endl;
		return false;
	}
}

void push(int x){
	stack[top]=x;
	++top;
}

void pop(){
	if(top==0){
		cout<<-1<<endl;
	}else{
	cout<<stack[top-1]<<endl;
	--top;
	}
	
}
void istop(){
	if(top==0){
		cout<<-1<<endl;
	}else{
		cout<<stack[top-1]<<endl;
	}

}

void size(){
	cout<<top<<endl;
}

int main(){
	int N;
	cin>>N;
	cin.ignore();
	for(int i=0;i<N;++i){
		string a;
		getline(cin,a);
		if(a=="top"){
			istop();
		}else if(a=="pop"){
			pop();
		}else if(a=="size"){
			size();
		}else if(a=="empty"){
			empty();
		}else{
			string b = a.substr(5, a.size()-5);
			int c=stoi(b);
			push(c);
		}
	}
}