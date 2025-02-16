#include <iostream>
#include <string>
using namespace std;

int main(){
	int N;
	cin>>N;
	for(int i=0;i<N;++i){
		string OX;
		cin>>OX;
		int score=0;
		int count=0;
		for(int j=0;j<OX.length();++j){
			if(OX[j]=='O'){
				count++;
				score+=count;
			}else{
				count=0;
			}
		}
		cout<<score<<endl;
	}
	
	
}