#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	string S;
	cin>>S;
	vector<int> alphabet(27,0);
	for(int i=0;i<S.length();++i){
		S[i]=toupper(S[i]);
		int a=int(S[i]-64);
		alphabet[a]++;
	}
	int max_index = max_element(alphabet.begin(), alphabet.end()) - alphabet.begin();
	sort(alphabet.begin(),alphabet.end(),greater<>());
	if(alphabet[0]==alphabet[1]){
		cout<<'?';
	}else{
		cout<<char(64+max_index);
	}
}