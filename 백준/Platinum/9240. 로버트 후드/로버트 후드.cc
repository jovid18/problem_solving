#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>
#include <cmath>
using namespace std;
using ll=long long;
struct Point{
	ll x,y;
	bool operator< (const Point&a){
		return y==a.y?x<a.x:y<a.y;
	}
	bool operator==(const Point &a){
		return y==a.y&&x==a.x;
	}
	bool operator<=(const Point &a){
		return y==a.y?x<=a.x:y<=a.y;
	}
	friend ostream& operator<< (std::ostream &out, const Point &point){
		out<< point.x << " " << point.y;
		return out;
	}
};
int N,T;
vector<Point> A;
vector<int> AH;
ll ccw(const Point &a, const Point &b, const Point &c)
{
    return a.x*b.y+b.x*c.y+c.x*a.y-b.x*a.y-c.x*b.y-a.x*c.y;
}
ll ccw4(const Point &a, const Point &b, const Point &c, const Point &d){
	Point dcopy={d.x-c.x+b.x,d.y-c.y+b.y};
	return ccw(a,b,dcopy);
}
ll dist(Point a, Point b)
{
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
bool comp(const Point &a,const Point &b){
	return a.y==b.y?a.x<b.x:a.y<b.y;
}
bool compA(const Point &a, const Point &b){
	ll c=ccw(A[0],a,b);
	if(c==0){
		return dist(A[0],a)<dist(A[0],b);
	}
	return c>0;
}

void make_convex(vector<Point> &P,vector<int> &PH){
	PH.clear();
	int N=P.size();
	if(P.size()==1){
		PH.push_back(0);
	}else if(P.size()==2){
		PH.push_back(0);
		PH.push_back(1);
	}else{
		PH.push_back(0);
		PH.push_back(1);
		int next=2;
		while(next<N){
			while(PH.size()>=2){
				int first,second;
				second=PH.back();
				PH.pop_back();
				first=PH.back();
				if(ccw(P[first],P[second],P[next])>0){
					PH.push_back(second);
					break;
				}
			}
			PH.push_back(next++);
		}
	}
}
int main(){
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	T=1;
	cout.precision(12);
	while(T--){
		cin>>N;
		A.resize(N);
		for(int i=0;i<N;++i){
			cin>>A[i].x>>A[i].y;
		}
		if(N==2){
			cout<<sqrt(dist(A[0],A[1]));
			return 0;
		}
		sort(A.begin(),A.end(),comp);
		sort(A.begin()+1,A.end(),compA);
		make_convex(A, AH);
		int a=0,b=1,c=1,d=2;
		int ansa=0,ansc=1;
		ll maxd=dist(A[AH[a]],A[AH[c]]);
		int count=2*AH.size();
		while(count--){
			if(ccw4(A[AH[a]],A[AH[b]],A[AH[c]],A[AH[d]])>0){
				c=(c+1)%AH.size();
				d=(d+1)%AH.size();
			}else{
				a=(a+1)%AH.size();
				b=(b+1)%AH.size();
			}
			if(maxd<dist(A[AH[a]],A[AH[c]])){
				maxd=dist(A[AH[a]],A[AH[c]]);
				ansa=a;
				ansc=c;
			}
		}
		cout<<sqrt(maxd);
	}
}
