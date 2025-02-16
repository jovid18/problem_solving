#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

int N,M;
vector<int> t;
vector<vector<int>> s;
int cycle=0;

int time(int a, int b, const vector<int> &t){
	if(a<b){
		return t[b-1]-t[a-1];
	}else{
		return cycle-time(b,a,t);
	}
}
bool compare1(vector<int> a, vector<int> b){
	return a[2]>b[2];
}
bool compare2(vector<int> a, vector<int> b){
	return a[3]>b[3];
}
int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>N>>M;
	t.resize(N+1,0);
	
	for(int i=1;i<=N;++i){
		cin>>t[i];
		cycle+=t[i];
	}
	for(int i=1;i<=N;++i){
		t[i]+=t[i-1];
	}
	s.resize(M);
	for(int i=0;i<M;++i){
		s[i].resize(4);
		cin>>s[i][0]>>s[i][1]>>s[i][2];
	}
	
	int max=s[0][2];
	for(int i=0;i<M;++i){
		int share=s[i][2]/cycle;
		if(time(0,s[i][0],t)<s[i][2]%cycle){
			s[i][3]=(share+1)*(cycle)+time(0,s[i][0],t)+time(s[i][0],s[i][1],t);
		}else{
			s[i][3]=(share)*cycle+time(0,s[i][0],t)+time(s[i][0],s[i][1],t);
		}
	}
	sort(s.begin(),s.end(),compare2);
	cout<<s[0][3];
}