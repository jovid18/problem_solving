#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int K,R,INF=1e9;
vector<pair<int,int>> E(4),C;
void print(void){
	sort(E.begin(),E.end());
	for(auto e: E){
		cout<<e.second<<" ";
	}
	cout<<'\n';
}
void M(int &minus1, int &minus2,int &plus){
	minus1--;
	minus2--;
	plus+=2;
}
bool bysize(pair<int,int> a, pair<int,int> b){
	return a.second<b.second;
}
int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin>>K;
	for(int i=0;i<=3;++i){
		E[i].first=i;
		cin>>E[i].second;
	}
	auto copy=E;
	for(int i=0;i<=3;++i){
		E=copy;
		if(i!=3) swap(E[i],E[3]);
		int count=1;
		while(count++){
			sort(E.begin(),E.end());
			if(i!=3)swap(E[i],E[3]);
			sort(E.begin(),E.end()-1,bysize);
			int &a=E[0].second,&b=E[1].second,&c=E[2].second,&d=E[3].second;
			if(!(a+b+c)) break;
			if(b==0&&d==0){
				count=INF;
				break;
			}
			if((a+b+c)%2==1){
				if(d==0){
					M(b,c,d);
					continue;
				}
				M(c,d,b);
				continue;
			}
			if(a+b>=c){
				M(c,b,d);
				continue;
			}else{
				if(b==0){
					M(c,d,b);
					continue;
				}else{
					M(b,c,a);
					continue;
				}
			}
		}
		C.push_back({count,i});
	}
	sort(C.begin(),C.end());
	R=C[0].second;
	E=copy;
	if(R!=3) swap(E[R],E[3]);
	print();
	while(1){
		sort(E.begin(),E.end());
		if(R!=3)swap(E[R],E[3]);
		sort(E.begin(),E.end()-1,bysize);
		int &a=E[0].second,&b=E[1].second,&c=E[2].second,&d=E[3].second;
		if(!(a+b+c)){
			break;
		}
		if((a+b+c)%2==1){
			if(d==0){
				M(b,c,d);
				print();
				continue;
			}
			M(c,d,b);
			print();
			continue;
		}
		if(a+b>=c){
			M(c,b,d);
			print();
			continue;
		}else{
			if(b==0){
				M(c,d,b);
				print();
				continue;
			}else{
				M(b,c,a);
				print();
				continue;
			}
		}
	}
}