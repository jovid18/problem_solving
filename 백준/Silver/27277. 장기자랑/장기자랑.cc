#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> soldier;
int N;
int main(){
	cin>>N;
	soldier.resize(N);
	for(int i=0;i<N;++i){
		cin>>soldier[i];
	}
	sort(soldier.begin(),soldier.end());
	vector<int> answer(N);
	int count1=0;
	for(int i=1;i<N;i+=2){
		answer[i]=soldier[count1];
		count1++;
	}
	int count2=N-1;
	for(int i=0;i<N;i+=2){
		answer[i]=soldier[count2];
		count2--;
	}
	
	int count3=answer[0];
	for(int i=1;i<N;++i){
		if(answer[i-1]<answer[i]){
			count3+=answer[i]-answer[i-1];
		}
		
	}
	cout<<count3;
	
}