#include <iostream>
using namespace std;
int N;
int main(){
    cin>>N;
    for(int i=N;i>=1;--i){
        int j=i;
        while(j--){
            cout<<'*';
        }
        cout<<endl;
    }
}