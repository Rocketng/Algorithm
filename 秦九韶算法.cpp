#include <iostream>
#include <algorithm>
using namespace std;
#define max 1000
int a[max];  //ϵ��a ������������Ϊa0,a1````an; 
int N,X;     //����ʽ�Ľף��Լ�x��ֵ

int fun(int n){
	if(n==0)
	return a[0];
	else{
		int b=a[0];
		a[0]=a[N-n+1];
		return fun(n-1)*X+b;
	}
} 

int main(){

	cin>>N>>X; 
	for(int i=0;i<=N;i++){
		cin>>a[i]; 
	}
	//������ 
	cout<<fun(N)<<endl;
	return 0;
} 
