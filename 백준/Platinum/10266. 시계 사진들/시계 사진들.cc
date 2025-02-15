#include <iostream>
#include <string>
#include <vector>
using namespace std;
int N;
string orig(360000,'0'),comp(360000,'0');
vector<int> findpi(string s){
	int m=s.size();
	vector<int> pi(m,0);
	int j=0;
	for(int i=1;i<m;++i){
		while(j>0&&s[i]!=s[j]){
			j=pi[j-1];
		}
		if(s[i]==s[j]){
			pi[i]=++j;
		}
	}
	return pi;
}

vector<int> kmp(string t,string p){
	int n=t.size(),m=p.size(),j=0;
	vector<int> v;
	auto pi=findpi(p);
	for(int i=0;i<n;++i){
		while(j>0&&t[i]!=p[j]) j=pi[j-1];
		if(t[i]==p[j]){
			if(j==m-1){
				v.push_back(i-m+1);
				j=pi[j];
			}else{
				j++;
			}
		}
	}
	return v;
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	for(int i=0;i<N;++i){
		int a;
		cin>>a;
		orig[a]='1';
	}
	for(int i=0;i<N;++i){
		int a;
		cin>>a;
		comp[a]='1';
	}
	orig+=orig;
	auto ans=kmp(orig,comp);
	if(ans.size()>0){
		cout<<"possible";
	}else{
		cout<<"impossible";
	}
}
