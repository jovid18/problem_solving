#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int a,b,c;
	cin>>a>>b>>c;
	while(a!=0){
		vector<int> tri;
		tri.push_back(a);
		tri.push_back(b);
		tri.push_back(c);
		sort(tri.begin(),tri.end());
		if(tri[2]*tri[2]==tri[1]*tri[1]+tri[0]*tri[0]){
			cout<<"right"<<endl;
		}else{
			cout<<"wrong"<<endl;
		}
		cin>>a>>b>>c;
	}
}