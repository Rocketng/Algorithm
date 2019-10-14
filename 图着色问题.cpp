#include <iostream>
#include <string>
using namespace std;
#define N 100
int n;
int arc[N][N];         //存储顶点之间边的情况
int color[N];

int OK(int k){
	for(int i=0;i<k;i++){
		if(arc[k][i]==1&&color[i]==color[k])
		return 0;
	}
	return 1;
} 

void GraphColor(int m){
	int i,k;
	for(i=0;i<n;i++){
		color[i]=0;
	}
	k=0;
	while(k>=0){
		color[k]=color[k]+1;    //取下一种颜色
		while(color[k]<=m){
			if(OK(k))
			break;
			else
			color[k]=color[k]+1;   //搜索下一个颜色 
		} 
		
		if(color[k]<=m&&k==n-1){
			for(i=0;i<n;i++)
			cout<<color[i]<<" ";
			return;
		}
		
		if(color[k]<=m&&k<n-1)
		k=k+1;
		else
		color[k--]=0; 
	}
}


int main(){
	int m;
	cout<<"请输入顶点个数和边的条数：";
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		arc[a-1][b-1]=1; 
	}
	GraphColor(3);
	return 0;
}
