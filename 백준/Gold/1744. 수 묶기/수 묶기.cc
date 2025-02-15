#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector<int> pos;
vector<int> neg;
int zero,one;
int main(){
	cin>>N;
	for(int i=0;i<N;++i){
		int a;
		cin>>a;
		if(a<0){
			neg.push_back(a);
		}else if(a==0){
			zero++;
		}else if(a==1){
			one++;
		}else{
			pos.push_back(a);
		}
	}
	sort(pos.begin(),pos.end(),greater<>());
	sort(neg.begin(),neg.end());
	int ans=0;
	for(int i=0;i+1<pos.size();i+=2){
		ans+=pos[i]*pos[i+1];
	}
	if(pos.size()%2==1) ans+=pos[pos.size()-1];
	ans+=one;
	for(int i=0;i+1<neg.size();i+=2){
		ans+=neg[i]*neg[i+1];
	}
	if(neg.size()%2==1){
		if(!zero) ans+=neg[neg.size()-1];
	}
	cout<<ans;
}