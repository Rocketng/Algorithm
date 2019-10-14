#include <iostream>
#include <algorithm>
using namespace std;

int func1(int a[],int n){
	int Dp[n];
	Dp[0]=a[0];
	for(int i=1;i<n;i++){
		if(Dp[i-1]>0){
			Dp[i]=Dp[i-1]+a[i];
		}else{
			Dp[i]=a[i];
		}
	}
	int max=0,start,end;
	for(int i=0;i<n;i++){
		if(Dp[i]>max){
			end=i;
			max=Dp[i];
		}
	}
	
	for(int i=end;i>=0;i--){
		if(Dp[i]<=0){
			start=i+1;
			break;
		}
	}
	
	//打印最大子段
	cout<<"最大子段："; 
	for(int i=start;i<=end;i++)
	cout<<a[i]<<"  "; 
	cout<<endl;
	return max;
}

int func2(int a[],int left,int right){
	int center;
	int left_sum,right_sum,sum;
	int left_max,right_max;
	left_max=right_max=0;
	
	if(left==right)
	return a[left];
	
	center=(left+right)/2;
	sum=0;
	for(int i=center;i>=0;i--){
		sum+=a[i];
		if(sum>left_max){
			left_max=sum;
		}
	}
	sum=0;
	for(int i=center+1;i<=(right-left);i++){
		sum+=a[i];
		if(sum>right_max){
			right_max=sum;
		}
	}
	sum=left_max+right_max;
	left_sum=func2(a,left,center);
	right_sum=func2(a,center+1,right);
	sum=max(sum,left_sum);
	sum=max(sum,right_sum);
	
	return sum;	
} 

int func3(int a[],int n){
	int i,j;
	int max;
	int start,end;
	for(int i=0;i<n;i++){
		int sum=0;
		for(int j=i;j<n;j++){
			sum+=a[j];
			if(sum>max){
				max=sum;
				start=i;
				end=j;
			}
		}
	}
	cout<<"最大子段：";
	for(int i=start;i<=end;i++){
		cout<<a[i]<<"  ";
	}
	cout<<endl;
	return max;
}

int main(){
	int n;
	cout<<"请输入数组长度："; 
	cin>>n;
	int code[n];
	for(int i=0;i<n;i++){
		cin>>code[i];
	}
	
	cout<<"动态规划算法："<<func1(code,n)<<endl;
	cout<<"分治法："<<func2(code,0,n-1)<<endl;
	cout<<"蛮力法："<<func3(code,n)<<endl; 
	
	return 0;
} 
