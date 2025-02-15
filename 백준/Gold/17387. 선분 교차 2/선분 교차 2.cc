#include <iostream>
#include <vector>
using namespace std;

int ccw(pair<long long ,long long> p1, pair<long long,long long> p2, pair<long long,long long> p3){
	long long s = p1.first * p2.second + p2.first * p3.second + p3.first * p1.second;
    s -= (p1.second * p2.first + p2.second * p3.first + p3.second * p1.first);
    if (s > 0) return 1;
    else if (s == 0) return 0;
    else return -1; 
}

int main(){
	long long a,b,c,d,e,f,g,h;
	cin>>a>>b>>c>>d>>e>>f>>g>>h;
	pair<int,int> p1={a,b};
	pair<int,int> p2={c,d};
	pair<int,int> p3={e,f};
	pair<int,int> p4={g,h};
	int x=ccw(p1,p2,p3)*ccw(p1,p2,p4);
	int y=ccw(p3,p4,p1)*ccw(p3,p4,p2);
	if(x==0&&y==0){
		if(p1>p2) swap(p1,p2);
		if(p3>p4) swap(p3,p4);
		cout<<(p3<=p2&&p1<=p4);
		return 0;
	}
	cout<<(x<=0&&y<=0);
}