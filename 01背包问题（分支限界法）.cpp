#include <iostream>
#include <cmath>
using namespace std;

int Bound(int* Weights,int* Values,int n,int W,int num,int current_w,int current_v){
	int i=num+1;
	for(;i<n;i++){
		if(current_w+Weights[i]<W){
			current_v+=Values[i];
			current_w+=Weights[i];
		}else{
			current_v+=(Values[i]/Weights[i])*(W-current_w);
			current_w=W;
			return current_v;
		}
	}
	return current_v;
}

int* fun(int *Weights,int* Values,int W,int n){
	int *X=new int[n];
	int *Y=new int[n];
	int Weight=0;
	int Profit=0;
	
	int current_w=0,current_v=0;
	
	int i=0;
	while(true){
		while(i<n&&current_w+Weights[i]<=W){
			X[i]=1;
			current_v+=Values[i];
			current_w+=Weights[i];
			i++;
		}
		
		//如果由于i==n结束，说明神度搜索到最底层了
		if(i>=n){
			Weight=current_w;
			Profit=current_v;
			i=n;
			for(int i=0;i<n;i++){
				Y[i]=X[i];
			}
		} else{
			//第i个物品放不下
			X[i]=0; 
		}
		
		//如果不能获得更大的价值，舍弃当前点 ，进行回溯 
		while(Bound(Weights,Values,n,W,i,current_w,current_v)<=Profit){
			while(i!=0&&X[i]!=1){
				i--;
			}
			if(i==0){
				cout<<"最大价值："<<Profit<<endl;
				return Y;
			}
			X[i]=0;
			current_v-=Values[i];
			current_w-=Weights[i];
		} 
		i++;
	}
}

int main(){
	int n,W;
	cout<<"输入物品个数："; 
	cin>>n;
	cout<<"请输入背包容量："; 
	cin>>W; 
	int Weight[n];
	int Value[n];
	int *path; 
	cout<<"请依次输入n个物品的质量和价值(V/W从大到小)："<<endl;
	for(int i=0;i<n;i++){
		cin>>Weight[i]>>Value[i]; 
	} 
	
	path=fun(Weight,Value,W,n);
	for(int i=0;i<n;i++)
	cout<<path[i]<<" ";
	
	return 0;
}

