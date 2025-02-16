#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
	vector<string> line;
	int N;
	cin>>N;
	cin.ignore();
	for(int i=0;i<N;i++){
		string x;
		getline(cin,x);
		line.push_back(x);
	}
	
	for(int i=1;i<=N;i++){
		cout<<i<<". "<<line[i-1]<<endl;
	}
	return 0;
}