#include <iostream>
using namespace std;

void func(int weight[],int value[],int W,int n){
	//Dp[i][j],��ʾ��������Ϊjʱ��ǰi����Ʒ��װ�뱳��������ֵ�� 
	int Dp[n+1][W+1];
	//��ʼ��һ�У���һ��Ϊ0
	for(int i=0;i<=n;i++){
		Dp[i][0]=0;
	} 
	for(int j=0;j<=W;j++){
		Dp[0][j]=0;
	}
	//��������ֵ 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=W;j++){
			if(j<weight[i-1]){
				Dp[i][j]=Dp[i-1][j];
			}else{
				Dp[i][j]=max(Dp[i-1][j],Dp[i-1][j-weight[i-1]]+value[i-1]);
			}
		}
	}
	
	//���ѡ����� 
	int path[n];
	for(int i=n,j=W;i>0;i--){
		if(Dp[i][j]>Dp[i-1][j]){
			path[i-1]=1;
			j=j-weight[i-1];
		}else{
			path[i-1]=0;
		}
	} 
	for(int i=0;i<n;i++)
	cout<<path[i]<<" ";
	cout<<endl;
	
	cout<<"����ֵΪ��"<<Dp[n][W]<<endl; 
}

int main(){
	int n,W;
	cout<<"��������Ʒ������";
	cin>>n;
	
	int weight[n],value[n];
	cout<<"����������"<<n<<"����Ʒ�������ͼ�ֵ��"<<endl;
	for(int i=0;i<n;i++){
		cin>>weight[i]>>value[i]; 
	} 
	cout<<"�����뱳��������";
	cin>>W; 
	
	func(weight,value,W,n);
	
	return 0;
} 
