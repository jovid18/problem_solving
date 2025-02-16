#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>
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
		out<< point.x << " " << point.y<<" ";
		return out;
	}
};
int N,M,T;
vector<Point> A,B;
vector<int> AH,BH;
ll ccw(const Point &a, const Point &b, const Point &c)
{
    return a.x*b.y+b.x*c.y+c.x*a.y-b.x*a.y-c.x*b.y-a.x*c.y;
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
bool compB(const Point &a, const Point &b){
	ll c=ccw(B[0],a,b);
	if(c==0){
		return dist(B[0],a)<dist(B[0],b);
	}
	return c>0;
}
bool inside(vector<Point> &S,vector<int> &V, Point &P){
	int n=V.size();
	int cnt=0;
	pair<double,double> pi,pj,q={P.x,P.y};
	for(int i=0;i<V.size();++i){
		int j=(i+1)%V.size();
		pi={S[V[i]].x,S[V[i]].y};
		pj={S[V[j]].x,S[V[j]].y};
		if((pi.second>q.second)!=(pj.second>q.second)){
			double L=(pj.first-pi.first)*(q.second-pi.second)/(pj.second-pi.second)+pi.first;
			if(q.first<L) cnt++;
		}
	}
	return cnt%2>0;
}

bool cross(Point &p1,Point &p2,Point &p3,Point &p4){
	ll x=ccw(p1,p2,p3)*ccw(p1,p2,p4);
	ll y=ccw(p3,p4,p1)*ccw(p3,p4,p2);
	if(x==0&y==0){
		if(p2<p1) swap(p1,p2);
		if(p4<p3) swap(p3,p4);
		return p3<=p2&&p1<=p4;
	}
	return (x<=0&&y<=0);
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
	cin>>T;
	while(T--){
		cin>>N>>M;
		A.resize(N);
		B.resize(M);
		AH.clear();
		BH.clear();
		for(int i=0;i<N;++i){
			cin>>A[i].x>>A[i].y;
		}
		for(int i=0;i<M;++i){
			cin>>B[i].x>>B[i].y;
		}
		sort(A.begin(),A.end(),comp);
		sort(B.begin(),B.end(),comp);
		sort(A.begin()+1,A.end(),compA);
		sort(B.begin()+1,B.end(),compB);
		make_convex(A, AH);
		make_convex(B, BH);
		bool ans=true;
		for(auto e:AH){
			if(ans) ans=!inside(B,BH,A[e]);
		}
		for(auto e:BH){
			if(ans) ans=!inside(A,AH,B[e]);
		} 
		for(int i=0;i<AH.size();++i){
			for(int j=0;j<BH.size();++j){
				if(!ans) continue;
				ans=!cross(A[AH[i]],A[AH[(i+1)%AH.size()]],B[BH[j]],B[BH[(j+1)%BH.size()]]);
			}
		}
		cout<<(ans?"YES":"NO")<<'\n';
	}
}
