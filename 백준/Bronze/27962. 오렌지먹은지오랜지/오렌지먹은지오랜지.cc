#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int N;
string S;
bool ans=false;
int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>N>>S;
	for(int i=1;i<N;++i){
		string start=S.substr(0,i);
		string end=S.substr(N-i,i);
		int check=0;
		for(int j=0;j<i;++j){
			if(start[j]!=end[j]){
				check++;
			}
		}
		if(check==1){
			ans=true;
			break;
		}
	}
	if(ans){
		cout<<"YES";
	}else{
		cout<<"NO";
	}
}