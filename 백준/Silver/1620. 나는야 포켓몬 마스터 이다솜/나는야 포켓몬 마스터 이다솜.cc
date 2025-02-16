#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
unordered_map <string,int> pokemon;
string pokemon2[1000001];

int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int N,M;
	cin>>N>>M;
	for(int i=1;i<=N;++i){
		string a;
		cin>>a;
		pokemon[a]=i;
		pokemon2[i-1]=a;
	}
	for(int i=1;i<=M;++i){
		string a;
		cin>>a;
		bool intcheck=true;
		if (isdigit(a[0]) == false) {
			intcheck=false;
		}
		
		if(intcheck){
			int b=stoi(a);
			cout<<pokemon2[b-1]<<'\n';
		}else{
			auto iter=pokemon.find(a);
			cout<<iter->second<<'\n';
		}
	}
}