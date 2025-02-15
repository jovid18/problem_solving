#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
vector<int>ans(10,0);
void count_digits(int n,int p){while(n)ans[n%10]+=pow(10,p-1),n/=10;}
void count_pages(int a,int b,int p){
    if(a>b)return;
    while(a%10!=0&&a<=b)count_digits(a,p),a++;
    while(b%10!=9&&a<=b)count_digits(b,p),b--;
    if(a>b)return;
    int pages=b/10-a/10+1;
    for(int i=0;i<10;i++)ans[i]+=pages*pow(10,p-1);
    count_pages(a/10,b/10,p+1);
}
int main(){
    int n;
    cin>>n;
    count_pages(1,n,1);
    for(int i=0;i<10;i++)cout<<ans[i]<<" ";
    return 0;
}
