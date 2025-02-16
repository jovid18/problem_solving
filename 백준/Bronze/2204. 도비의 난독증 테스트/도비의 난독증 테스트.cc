#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main(){
	int n;
	while(cin>>n&&n!=0){
		vector<pair<string,string>> wordlist;
		for(int i=0;i<n;i++){
			string a;
			cin>>a;
			string b=a;
			for(int j=0;j<b.length();j++){
				if(b[j]>='A'&&b[j]<='Z'){
					b[j]=b[j]+'a'-'A';
				}
			}
			wordlist.push_back(pair<string,string>(b,a));
		}
		sort(wordlist.begin(),wordlist.end());
		cout<<wordlist[0].second<<endl;
	}
}