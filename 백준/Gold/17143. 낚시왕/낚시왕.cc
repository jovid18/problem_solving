#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int R,C,M;
struct shark{
	int r=0;
	int c=0;
	int v=0;
	int d=0;
	int m=0;
};
std::ostream& operator<<(std::ostream& os, const shark& s) {
  os <<s.r<<" "<<s.c<<" "<<s.v<<" "<<s.d<<" "<<s.m<<endl;
  return os;
}

bool bypoint(const shark &a,const shark &b){
	if(a.r!=b.r){
		return a.r<b.r;
	}
	if(a.c!=b.c){
		return a.c<b.c;
	}
	return a.m>b.m;
}
bool bycolumn(const shark &a,const shark &b){
	if(a.c!=b.c){
		return a.c<b.c;
	}
	return a.r<b.r;
}

void move(shark &a){
	int ad=a.d;
	int ar=a.r;
	int ac=a.c;
	if(ad==1){
		if(0<=a.v&&a.v<=ar-1){
			a.r-=a.v;
		}else if(ar<=a.v&&a.v<=ar+R-2){
			a.d=2;
			a.r=a.v-a.r+2;
		}else{
			a.r=2*R-2+a.r-a.v;
		}
	}else if(ad==2){
		if(0<=a.v&&a.v<=R-ar){
			a.r+=a.v;
		}else if(R-ar+1<=a.v&&a.v<=2*R-ar-1){
			a.d=1;
			a.r=2*R-a.r-a.v;
		}else{
			a.r=a.v-2*R+a.r+2;
		}
	}else if(ad==3){
		if(0<=a.v&&a.v<=C-ac){
			a.c+=a.v;
		}else if(C-ac+1<=a.v&&a.v<=2*C-ac-1){
			a.d=4;
			a.c=2*C-a.c-a.v;
		}else{
			a.c=a.v-2*C+a.c+2;
		}
	}else{
		if(0<=a.v&&a.v<=ac-1){
			a.c-=a.v;
		}else if(ac<=a.v&&a.v<=ac+C-2){
			a.d=3;
			a.c=a.v-a.c+2;
		}else{
			a.c=2*C-2+a.c-a.v;
		}
	}
}
int answer=0;
vector<shark> S;
int main(){
	cin>>R>>C>>M;
	S.resize(M);
	for(int i=0;i<M;++i){
		cin>>S[i].r>>S[i].c>>S[i].v>>S[i].d>>S[i].m;
		if(S[i].d==1||S[i].d==2){
			S[i].v%=2*(R-1);
		}else{
			S[i].v%=2*(C-1);
		}
	}
	if (M==0){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=C;++i){
		sort(S.begin(),S.end(),bycolumn);
		auto iter=S.begin();
		while(iter!=S.end()){
			if((*iter).c==i){
				answer+=(*iter).m;
				S.erase(iter);
				break;
			}
			iter++;
		}
		for(int j=0;j<S.size();++j){
			move(S[j]);
		}
		if(S.size()<=1) continue;
		sort(S.begin(),S.end(),bypoint);
		vector<shark> Scopy;
		shark now=S[0];
		Scopy.push_back(now);
		for(int j=1;j<S.size();++j){
			if(S[j].r==now.r&&S[j].c==now.c) continue;
			now=S[j];
			Scopy.push_back(now);
		}
		S=Scopy;
	}
	cout<<answer;
}
