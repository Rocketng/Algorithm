#include <iostream>
#include <string>
using namespace std;

int Dp[1000][1000];

int ASM(string P,int m,string T,int n){
	int i,j;
	for(j=1;j<=n;j++)       //��ʼ��0�� 
	Dp[0][j]=j;
	for(i=0;i<=m;i++)       //��ʼ��0�� 
	Dp[i][0]=i;
	
	for(j=1;j<=n;j++){
		for(i=1;i<=m;i++){
			if(P[i-1]==T[j-1])
			Dp[i][j]=min(Dp[i-1][j-1],min(Dp[i-1][j]+1,Dp[i][j-1]+1));
			else
			Dp[i][j]=min(Dp[i-1][j-1]+1,min(Dp[i-1][j]+1,Dp[i][j-1]+1));
		}
	} 
	
	cout<<"K-����ƥ�������̣�"<<endl;
	for(int a=0;a<=m;a++){
		for(int b=0;b<=n;b++)
		cout<<Dp[a][b]<<" ";
		cout<<endl;
	} 
	return Dp[m][n];
}

int main(){
	cout<<"KֵΪ��"<<ASM("grammer",7,"grameer",7)<<endl;
	return 0;
} 
