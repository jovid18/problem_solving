#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
int a[1000000],temp[1000000];

int merge(int s,int m,int f){
    int i=s,j=m+1,k=s;
    int inv=0;
    while(i<=m&&j<=f){
        if(a[i]<=a[j]) temp[k++]=a[i++];
        else{
            temp[k++]=a[j++];
            inv+=(m+1-i);
        } 
    }
    while(i<=m) temp[k++]=a[i++];
    while(j<=f) temp[k++]=a[j++];
    for(int i=s;i<=f;++i) a[i]=temp[i];
    return inv;
}

int mergesort(int s,int f){
    if(s>=f) return 0;
    int m=(s+f)/2;
    int a_inv=mergesort(s,m);
    int b_inv=mergesort(m+1,f);
    int m_inv=merge(s,m,f);
    return a_inv+b_inv+m_inv;
}
int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<n;++i) cin>>a[i];
    cout<<mergesort(0,n-1);
}