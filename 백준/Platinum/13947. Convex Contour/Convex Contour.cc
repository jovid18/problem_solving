#include <bits/stdc++.h>
using namespace std;
#define int long long
int N;
string s;
const double pi=atan(1)*4;
int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    double ans=0;
    cin>>N>>s;
    bool onlyT=true;
    for(int i=0;i<N;++i){
        if(s[i]!='T') onlyT=false;
    }
    if(onlyT){
        cout<<2*N+1;
        return 0;
    }
    int left=N-1,right=0;
    for(int i=0;i<N;++i) if(s[i]!='T') right=i;
    for(int i=N-1;i>=0;--i) if(s[i]!='T') left=i;
    ans+=N;
    if(s[0]=='C') ans-=0.5;
    if(s[N-1]=='C') ans-=0.5;
    if(s[0]=='T'){
        ans+=1;
    }else if(s[0]=='C'){
        ans+=0.5*pi;
    }else{
        ans+=1;
    }
    if(s[N-1]=='T'){
        ans+=1;
    }else if(s[N-1]=='C'){
        ans+=0.5*pi;
    }else{
        ans+=1;
    }
    ans+=right-left;
    if(s[right]=='S') ans+=0.5;
    if(s[left]=='S') ans+=0.5;
    double ld=left;
    double rd=N-1-right;
    if(s[right]=='S'){
        if(rd!=0) ans+=sqrt(pow(1.0-sqrt(3)/2,2)+pow(rd-0.5,2));
    }else{
        if(rd!=0){
            double d=sqrt(pow(rd,2)+pow((sqrt(3)/2-0.5),2));
            double a=sqrt(pow(d,2)-pow(0.5,2));
            ans+=a;
            double theta1=atan((sqrt(3)/2-0.5)/rd);
            double theta2=atan(2.0*a);
            double theta=pi/2-theta1-theta2;
            ans+=0.5*theta;
        }
    }
    if(s[left]=='S'){
        if(ld!=0) ans+=sqrt(pow(1.0-sqrt(3)/2,2)+pow(ld-0.5,2));
    }else{
        if(ld!=0){
            double d=sqrt(pow(ld,2)+pow((sqrt(3)/2-0.5),2));
            double a=sqrt(pow(d,2)-pow(0.5,2));
            ans+=a;
            double theta1=atan((sqrt(3)/2-0.5)/ld);
            double theta2=atan(2.0*a);
            double theta=pi/2-theta1-theta2;
            ans+=0.5*theta;
        }
    }
    
    cout.precision(12);
    cout<<ans;
}