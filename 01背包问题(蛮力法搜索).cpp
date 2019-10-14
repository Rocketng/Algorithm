#include <iostream>
using namespace std;
int weight[100],value[100];		//物品重量和价值 
int Path[100],path[100];        //最终路径，与当前路径 
int W;   		//背包容量 
int N;    		//物品个数 
int Max;        //最大价值 
int V;          //当前价值 
int w;          //当前重量 

int func(int i){
	if(i>=N){
		if(V>Max&&w+value[i]<=W){
			Max=V;
			for(int i=0;i<N;i++)
			Path[i]=path[i];
		} 
		return Max;
	}
	
	//放入背包 
	w+=weight[i];
	V+=value[i];
	path[i]=1;
	func(i+1);

    //不放入背包 
	w-=weight[i];
	V-=value[i];
	path[i]=0;
	func(i+1);
	return Max;
}

int main(){
	cout<<"请输入物品个数：";
	cin>>N;
	
	cout<<"请输入背包容量：";
	cin>>W;
	
	cout<<"请依次输入每个物品的重量和价值:"<<endl;
	for(int i=0;i<N;i++)
	cin>>weight[i]>>value[i]; 
	
	cout<<"最大价值："<<func(0)<<endl;
	cout<<"物品存放详情:"<<endl;
	for(int i=0;i<N;i++)
	cout<<Path[i]<<" "; 
	return 0; 
} 
