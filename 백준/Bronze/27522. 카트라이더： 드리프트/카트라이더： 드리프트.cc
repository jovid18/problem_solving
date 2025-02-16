#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
struct record{
	int m=0;
	int ss=0;
	int sss=0;
	char T;
	bool operator< (const record &a){
		if(m==a.m&&(ss==a.ss)){
			return sss<a.sss;
		}
		if(m==a.m){
			return ss<a.ss;
		}
		return m<a.m;
	}
};
vector<record> P(8);

int main(){
	for(int i=0;i<8;++i){
		string s;
		cin>>s;
		cin>>P[i].T;
		auto one=s.substr(0,1);
		auto two=s.substr(2,2);
		auto three=s.substr(5,3);
		P[i].m=stoi(one);
		P[i].ss=stoi(two);
		P[i].sss=stoi(three);
	}
	sort(P.begin(),P.end());
	int r=0;
	int b=0;
	int score[8]={10,8,6,5,4,3,2,1};
	for(int i=0;i<8;++i){
		if(P[i].T=='R'){
			r+=score[i];
		}else{
			b+=score[i];
		}
	}
	if(r>b){
		cout<<"Red";
	}else{
		cout<<"Blue";
	}
}