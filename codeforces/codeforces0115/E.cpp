#include <bits/stdc++.h>
using namespace std;
#define int long long
int t;
int h,w,xa,ya,xb,yb;
int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>t;
    while(t--){
        cin>>h>>w>>xa>>ya>>xb>>yb;
        if(xa>=xb){
            // cout<<"case 0 ";
            cout<<"Draw\n";
            continue;
        }
        int xdiff=abs(xa-xb);
        int ydiff=abs(ya-yb);
        if((xa-xb)%2==0){
            //bob이 유리 즉, alice는 피하려고함
            if(ya==yb){
                // cout<<"case 1 ";
                cout<<"Bob\n";
                continue;
            }
            if(ya<yb){
                //alice가 bob이 왼쪽에 있음
                if(ya-1+abs(yb-ya)<=xdiff/2){
                    // cout<<"case 2 ";
                    cout<<"Bob\n";
                }else{
                    // cout<<"case 3 ";
                    cout<<"Draw\n";
                }

            }else{
                if(w-1-ya+abs(yb-ya)<xdiff/2){
                    // cout<<"case 4 ";
                    cout<<"Bob\n";
                }else{
                    // cout<<"case 5 ";
                    cout<<"Draw\n";
                }
            }
        }else{
            //alice가 유리 즉, bob은 피하려고 함
            if(ydiff<=1){
                // cout<<"case 6 ";
                cout<<"Alice\n";
                continue;
            }
            if(yb<ya){
                if(yb-1+abs(ya-yb)<=(xdiff+1)/2){
                    // cout<<"case 7 ";
                    cout<<"Alice\n";
                }else{
                    // cout<<"case 8 ";
                    cout<<"Draw\n";
                }
            }else{
                if(w-1-yb+abs(ya-yb)<(xdiff+1)/2){
                    // cout<<"case 9 ";
                    cout<<"Alice\n";
                }else{
                    // cout<<"case 10 ";
                    cout<<"Draw\n";
                }  
            }
        }
    }
}