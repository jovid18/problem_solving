#include <iostream>
#include <queue>

using namespace std;

int main(){
	int N;
	cin>>N;
	queue<int> card;
	for(int i=1;i<=N;++i){
		card.push(i);
	}
	
	for(int i=1;i<N;++i){
		card.pop();
		int a=card.front();
		card.pop();
		card.push(a);
	}
	cout<<card.front();
}