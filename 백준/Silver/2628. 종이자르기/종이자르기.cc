#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
	
	int garo;
	int sero;
	cin>>garo;
	cin>>sero;
	
	int cutting;
	cin>> cutting;
	
	vector<int> garocutnum;
	vector<int> serocutnum;
	garocutnum.push_back(0);
	serocutnum.push_back(0);
	garocutnum.push_back(garo);
	serocutnum.push_back(sero);
	
	for(int i=0; i<cutting;i++){
		int check;
		cin>>check;
		int cutnum;
		cin>>cutnum;
		
		if(check==1){
			garocutnum.push_back(cutnum);
		}else{
			serocutnum.push_back(cutnum);
		}
	}
	sort(garocutnum.begin(),garocutnum.end());
	sort(serocutnum.begin(),serocutnum.end());
	
	for(int i=0;i<garocutnum.size()-1;i++){
		int a= garocutnum[i];
		garocutnum[i]=garocutnum[i+1]-a;
	}
	garocutnum.pop_back();

	for(int i=0;i<serocutnum.size()-1;i++){
		int a= serocutnum[i];
		serocutnum[i]=serocutnum[i+1]-a;
	}
	serocutnum.pop_back();
	
	int maxsquare=0;
	for(auto giter=garocutnum.begin();giter!=garocutnum.end();giter++){
		for(auto siter=serocutnum.begin();siter!=serocutnum.end();siter++){
		
			if(maxsquare<(*giter)*(*siter)){
				maxsquare=(*giter)*(*siter);
			}
		}
	}
	cout<<maxsquare;
	return 0;
}