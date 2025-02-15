#include <iostream>
#include <string>
#include <vector>
using namespace std;

using tree=vector<vector<int>>;

int quadcheck(tree arr, int i){
	if(i==1){
		if(arr[0][0]==1){
			return 1;
		}else{
			return 0;
		}
	}else{
		tree arr1(i/2),arr2(i/2),arr3(i/2),arr4(i/2);
		for(int j=0;j<i/2;++j){
			for(int k=0;k<i/2;++k){
				arr1[j].push_back(arr[j][k]);
			}
		}
		for(int j=0;j<i/2;++j){
			for(int k=i/2;k<i;++k){
				arr2[j].push_back(arr[j][k]);
			}
		}
		for(int j=i/2;j<i;++j){
			for(int k=0;k<i/2;++k){
				arr3[j-i/2].push_back(arr[j][k]);
			}
		}
		
		for(int j=i/2;j<i;++j){
			for(int k=i/2;k<i;++k){
				arr4[j-i/2].push_back(arr[j][k]);
			}
		}
		int a=quadcheck(arr1,i/2);
		if(a==-1){
			return -1;
		}
		int b=quadcheck(arr2,i/2);
		if(b==-1){
			return -1;
		}
		int c=quadcheck(arr3,i/2);
		if(c==-1){
			return -1;
		}
		int d=quadcheck(arr4,i/2);
		if(d==-1){
			return -1;
		}
		if(a==1&&b==1&&c==1&&c==1){
			return 1;
		}else if(a==0&&b==0&&c==0&&d==0){
			return 0;
		}else{
			return -1;
		}
	}
}

void quad(tree arr,int i){
	if(i==1){
		cout<<arr[0][0];
	}else{
		tree arr1(i/2),arr2(i/2),arr3(i/2),arr4(i/2);
		for(int j=0;j<i/2;++j){
			for(int k=0;k<i/2;++k){
				arr1[j].push_back(arr[j][k]);
			}
		}
		for(int j=0;j<i/2;++j){
			for(int k=i/2;k<i;++k){
				arr2[j].push_back(arr[j][k]);
			}
		}
		for(int j=i/2;j<i;++j){
			for(int k=0;k<i/2;++k){
				arr3[j-i/2].push_back(arr[j][k]);
			}
		}
		
		for(int j=i/2;j<i;++j){
			for(int k=i/2;k<i;++k){
				arr4[j-i/2].push_back(arr[j][k]);
			}
		}
		
		
		int a=quadcheck(arr1,i/2);
		int b=quadcheck(arr2,i/2);
		int c=quadcheck(arr3,i/2);
		int d=quadcheck(arr4,i/2);
		if(a==0&&b==0&&c==0&d==0){
			cout<<0;
		}else if(a==1&&b==1&&c==1&d==1){
			cout<<1;
		}else{
			cout<<"(";
			quad(arr1,i/2);
			quad(arr2,i/2);
			quad(arr3,i/2);
			quad(arr4,i/2);
			cout<<")";
		}
	}
}

int main(){
	int N;
	cin>>N;
	tree mainarr(N,vector<int> (N,0));
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			char a=cin.get();
			if(a=='\n'){
				a=cin.get();
			}
			mainarr[i][j]=a-'0';
		}
	}
	quad(mainarr,N);
}