#include <bits/stdc++.h>
using namespace std;
int N;
bool O[500][500];
bool S[500][500];
void change(int i, int j){
    for(int k=0;k<N;++k){
        swap(O[i][k],O[j][k]);
        swap(S[i][k],S[j][k]);
    }
}
void XOR(int i, int j){
    for(int k=0;k<N;++k){
        O[j][k]^=O[i][k];
        S[j][k]^=S[i][k];
    }
}
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    cin>>N;
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            cin>>O[i][j];
        }
    }
    for(int i=0;i<N;++i){
        S[i][i]=1;
    }
    for(int j=0;j<N;++j){
        for(int i=j;i<N;++i){
            if(i==j){
                if(!O[i][j]){
                    for(int k=i+1;k<N;++k){
                        if(O[k][j]){
                            change(i,k);
                            break;
                        }
                    }
                }
            }else{
                if(O[i][j]) XOR(j,i);
            }
        }
        if(!O[j][j]){
            cout<<-1;
            return 0;
        }
    }
    for(int j=N-1;j>=0;--j){
        for(int i=j-1;i>=0;--i){
            if(O[i][j]) XOR(j,i);
        }
    }
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){        
            if(S[i][j]) cout<<j+1<<" ";
        }
        cout<<'\n';
    }
}