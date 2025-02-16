#include <iostream>
#include <cmath>
using namespace std;
const double pi = 3.14159265358979;
double a,b,c,i=1;
int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	while(cin>>a>>b>>c){
		if(a==0) break;
		cout<<"Triangle #"<<i<<'\n';
		cout<<fixed;
		cout.precision(3);
		if(a==-1&&b<c){
			cout<<"a = "<<sqrt(c*c-b*b)<<"\n\n";
		}else if(b==-1&&a<c){cout<<"b = "<<sqrt(c*c-a*a)<<"\n\n";
		}else if(c==-1){cout<<"c = "<<sqrt(a*a+b*b)<<"\n\n";
		}else{
			cout<<"Impossible."<<"\n\n";
		}
		cout.unsetf(ios::fixed);
		++i;
	}
}