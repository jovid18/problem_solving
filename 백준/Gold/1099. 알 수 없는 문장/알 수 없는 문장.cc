#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int checkstr(string a, string b){
	vector<char> A;
	vector<char> B;
	int point=0;
	for(int i=0;i<a.length();i++){
		A.push_back(a[i]);
		B.push_back(b[i]);
		if(a[i]!=b[i]){
			point++;
		}
	}
	sort(A.begin(),A.end());
	sort(B.begin(),B.end());
	if(A!=B){
		return -1;
	}
	return point;	
}

int main(){
	string sentence;
	cin>>sentence;
	vector<int> wordmin(sentence.length(),-1);
	int words;
	cin>>words;
	vector<vector<string>> wordlist(51);
	for(int i=1;i<=words;i++){
		string a;
		cin>>a;
		int n=a.length();
		wordlist[n].push_back(a);
	}
	wordmin.push_back(-1);
	int min=-1;
	for(int i=1;i<=sentence.length();++i){
		int icheck=-1;
		for(int j=0;j<i;++j){
				int check=-1;
			for(auto iter=wordlist[i-j].begin();iter!=wordlist[i-j].end();iter++){
				string iminusj=sentence.substr(j,i-j);
				int n=checkstr(iminusj,*iter);
				if(check==-1){
					check=n;
				}else{
					if(n>=0&&n<check){
						check=n;
					}
				}
				
			}
			if(j==0){
				icheck=check;
			}
			if(wordmin[j]>=0&&check>=0){
				int a=icheck;
				int b=wordmin[j]+check;
				if((a==-1&&b>-1)||(a>-1&&b>-1&&a>b)){
					icheck=b;
				}
			}
			
		}
		wordmin[i]=icheck;
		for(auto iter=wordmin.begin();iter!=wordmin.end();++iter){
		}
	}
	cout<<wordmin[sentence.length()]<<endl;
}