#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> STAR;


void star(int N,vector<string> &STAR){
	if(N==3){
		STAR[1]="*";
		STAR[2]="* *";
		STAR[3]="*****";
	}else{
		star(N/2,STAR);
		for(int i=1;i<=N/2;++i){
			string s="";
			for(int j=1;j<=N+1-2*i;j++){
			s+=" ";
			}
		STAR[N/2+i]=STAR[i]+s+STAR[i];
		}
	}
}
	
	

int main(){
	int N;
	cin>>N;
	STAR.resize(N+1);
	star(N,STAR);
	for(int i=1;i<=N;++i){
		string s="";
		for(int j=N-i;j>0;--j){
			s+=" ";
		}
		cout<<s<<STAR[i]<<s<<endl;
	}

}