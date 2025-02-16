#include <iostream>
#include <vector>
using namespace std;
using pll=pair<long long ,long long>;
int ccw(pll p1, pll p2, pll p3){
	long long s = p1.first * p2.second + p2.first * p3.second + p3.first * p1.second;
    s -= (p1.second * p2.first + p2.second * p3.first + p3.second * p1.first);
    if (s > 0) return 1;
    else if (s == 0) return 0;
    else return -1; 
}
void intersection(pll p1,pll p2, pll p3,pll p4){
	long long a=p1.first,b=p1.second,c=p2.first,d=p2.second,e=p3.first,f=p3.second,g=p4.first,h=p4.second;
	double p=(a-c)*(f-h)-(b-d)*(e-g);
	if(p==0){
		if(p1==p4){ 
			cout<<p1.first<<" "<<p1.second;
		}else if(p2==p3){
			cout<<p2.first<<" "<<p2.second;
		}
		return;
	}
	double x=(a*d-b*c)*(e-g)-(a-c)*(e*h-f*g);
	double y=(a*d-b*c)*(f-h)-(b-d)*(e*h-f*g);
	cout.fixed;
	cout.precision(15);
	cout<<x/p<<" "<<y/p;
}


int main(){
	long long a,b,c,d,e,f,g,h;
	cin>>a>>b>>c>>d>>e>>f>>g>>h;
	pll p1={a,b};
	pll p2={c,d};
	pll p3={e,f};
	pll p4={g,h};
	int ccw1=ccw(p1,p2,p3);
	int ccw2=ccw(p1,p2,p4);
	int ccw3=ccw(p3,p4,p1);
	int ccw4=ccw(p3,p4,p2);
	int x=ccw1*ccw2;
	int y=ccw3*ccw4;
	if(x==0&&y==0){
		if(p1>p2) swap(p1,p2);
		if(p3>p4) swap(p3,p4);
		if(p3<=p2&&p1<=p4){
			cout<<1<<endl;
			intersection(p1, p2, p3, p4);
		}else{
			cout<<0;
		}
		return 0;
	}
	if(x<=0&&y<=0){
		cout<<1<<endl;
		intersection(p1, p2, p3, p4);
	}else{
		cout<<0;
	}
}