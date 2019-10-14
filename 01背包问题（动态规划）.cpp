#include <iostream>
using namespace std;

void func(int weight[],int value[],int W,int n){
	//Dp[i][j],表示背包容量为j时，前i个物品能装入背包的最大价值。 
	int Dp[n+1][W+1];
	//初始第一列，第一行为0
	for(int i=0;i<=n;i++){
		Dp[i][0]=0;
	} 
	for(int j=0;j<=W;j++){
		Dp[0][j]=0;
	}
	//计算最大价值 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=W;j++){
			if(j<weight[i-1]){
				Dp[i][j]=Dp[i-1][j];
			}else{
				Dp[i][j]=max(Dp[i-1][j],Dp[i-1][j-weight[i-1]]+value[i-1]);
			}
		}
	}
	
	//输出选择情况 
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
	
	cout<<"最大价值为："<<Dp[n][W]<<endl; 
}

int main(){
	int n,W;
	cout<<"请输入物品个数：";
	cin>>n;
	
	int weight[n],value[n];
	cout<<"请依次输入"<<n<<"个物品的质量和价值："<<endl;
	for(int i=0;i<n;i++){
		cin>>weight[i]>>value[i]; 
	} 
	cout<<"请输入背包容量：";
	cin>>W; 
	
	func(weight,value,W,n);
	
	return 0;
} 
