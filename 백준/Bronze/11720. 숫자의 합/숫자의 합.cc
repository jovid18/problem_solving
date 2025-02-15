#include <iostream>
#include <string>
using namespace std;

int main(){
	int N;
	cin>>N;
	int score=0;
	for(int i=0;i<N;++i){
		char a;
		cin>>a;
		int d= a - '0';
		score+=d;
	}
	cout<<score;
	
	
}