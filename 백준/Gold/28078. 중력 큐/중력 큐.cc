#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <deque>
using namespace std;
using ll=long long;
int N;
string com;
char c;
int ball,screen;
bool a,b;
deque<int> Q;
int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>N;
	while(N--){
		cin>>com;
		if(com=="pop"){
			//pop
			if(!a&&!b){
				if(!Q.empty()){
					if(Q.front()==1){
						Q.pop_front();
						ball--;
					}else{
						Q.pop_front();
						screen--;
					}
				}
			}else if(a&&!b){
				if(!Q.empty()){
					Q.pop_front();
					screen--;
					while(!Q.empty()&&Q.front()==1){
						Q.pop_front();
						ball--;
					}
				}
			}else if(!a&&b){
				if(!Q.empty()){
					if(Q.front()==1){
						Q.pop_front();
						ball--;
					}else{
						Q.pop_front();
						screen--;
					}
				}
			}else{
				if(!Q.empty()){
					if(Q.front()==1){
						Q.pop_front();
						ball--;
					}else{
						Q.pop_front();
						screen--;
					}
				}
			}
		}else{
			cin>>c;
			if(com=="push"){
				if(c=='b'){
					//push b
					if(!a&&!b){
						Q.push_back(1);
						ball++;
					}else if(a&&!b){
						if(screen>0){
							Q.push_back(1);
							ball++;
						} 
					}else if(!a&&b){
						Q.push_back(1);
						ball++;
					}else{
						
					}
				}else{
					//push w
					Q.push_back(0);
					screen++;
				}
			}else if(com=="rotate"){
				if(c=='l'){
					//rotate l
					if(!a&&!b){
						a^=1;
						b^=1;
						while(!Q.empty()&&Q.back()==1){
							Q.pop_back();
							ball--;
						}
					}else if(a&&!b){
						a^=1;
					}else if(!a&&b){
						a^=1;
						b^=1;
						while(!Q.empty()&&Q.front()==1){
							Q.pop_front();
							ball--;
						}
					}else{
						a^=1;
					}
				}else{
					//rorate r
					if(!a&&!b){
						a^=1;
						while(!Q.empty()&&Q.front()==1){
							Q.pop_front();
							ball--;
						}
					}else if(a&&!b){
						a^=1;
						b^=1;
					}else if(!a&&b){
						a^=1;
						while(!Q.empty()&&Q.back()==1){
							Q.pop_back();
							ball--;
						}
					}else{
						a^=1;
						b^=1;
					}
				}
			}else{
				if(c=='b'){
					//count b
					cout<<ball<<'\n';
				}else{
					//count w
					cout<<screen<<'\n';
				}
			}
		}
	}
}