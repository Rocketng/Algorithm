#include <iostream>
#include <algorithm>
using namespace std;
int code[100005];
int fun(int *a,int n){
	if(n==1)
	return 0;
	else if(n==2){
	if(a[0]>a[1])
	return 0;
	else
	return 1;
	}else{
		if(code[fun(a,n/2)]>code[fun(a+n/2,n-n/2)+n/2])
		return fun(a,n/2);
		else
		return fun(a+n/2,n-n/2)+n/2;
	}
}
int main(){
	int n;
	cin>>n;
    for(int i=0;i<n;i++)
	cin>>code[i];
	cout<<"最大值位置："<<fun(code,n)+1<<endl;
	return 0;
} 
