#include <iostream>
#include <vector>
#include <string>
using namespace std;
string T,P;
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
	vector<int> f;
	auto pi=findpi(p);
	for(int i=0;i<n;++i){
		while(j>0&&t[i]!=p[j]) j=pi[j-1];
		if(t[i]==p[j]){
			if(j==m-1){
				if(((i-m+1)%m)!=0){
					return f;
				}
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
	string s;
	while(cin>>s&&s!="."){
		int n=0;
		for(int i=1;i<=s.size();++i){
			if(s.size()%i!=0) continue;
			string subs=s.substr(0,i);
			auto ans=kmp(s,subs);
			if(i*ans.size()==s.size()) n=max(n,(int)(s.size()/i));
		}
		cout<<n<<endl;
	}
}
