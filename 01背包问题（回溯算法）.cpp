#include <iostream>
using namespace std;
int Path[100];
void func(int weight[],int value[],int W,int n,int path[],int &Max,int V,int c,int start){
	if(c<=W){
		//Max=max(Max,V);
		if(V>Max){
			Max=V;
			for(int i=0;i<n;i++)
			Path[i]=path[i];      //保存存放路径 
		}
		
		for(int i=start;i<n;i++){
			c+=weight[i];
			V+=value[i];
			path[i]=1;
			func(weight,value,W,n,path,Max,V,c,i+1);
			c-=weight[i];
			V-=value[i];
			path[i]=0;
		}
	}
} 

int main(){
	int n,W;
	cout<<"请输入物品个数：";
	cin>>n;
	
	int weight[n],value[n];
	
	int path[n]={0};//用来记录取最大值时背包所放物品 
	
	cout<<"请依次输入"<<n<<"个物品的质量和价值："<<endl;
	for(int i=0;i<n;i++){
		cin>>weight[i]>>value[i]; 
	} 
	cout<<"请输入背包容量：";
	cin>>W; 
	int Max=0;
	func(weight,value,W,n,path,Max,0,0,0);
	cout<<"背包能装最大价值:"<<Max<<endl;
	cout<<"物品存放详情："<<endl;
	for(int i=0;i<n;i++)
	cout<<Path[i]<<" "; 
	return 0;
} 
