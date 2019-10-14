#include <iostream>
#include <string>

using namespace std;

int color[100]; 
int arc[100][100];   //存放图中变得距离
int n; 

int OK(int i){
	for(int j=0;j<n;j++){
		if(arc[i][j]==1&&color[i]==color[j])
		return 0;
	}
	return 1;
}

void ColorGrap(){
	int k=0;
	int flag=1;   //表示图中还有没有染色的边
	while(flag==1){
		k++;
		flag=0;
		
		for(int i=0;i<n;i++){
		
			if(color[i]==0){
				color[i]=k;        //顶点i涂颜色k  
				if(!OK(i)){        //发生冲突取消着色 
					color[i]=0;
					flag=1;
				}
			}
		} 
	} 
} 

int main(){
	int m;
	cout<<"请输入点的个数和边的条数：";
	cin>>n>>m; 
    
    //输入边
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		arc[a-1][b-1]=1;
		arc[b-1][a-1]=1;
	} 
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
		cout<<arc[i][j]<<" ";
		cout<<endl;
	} 
    cout<<"888"<<endl;
    ColorGrap();
     cout<<"888"<<endl;
    //输出结果
	for(int i=0;i<n;i++){
		cout<<color[i]<<" ";
	} 
	return 0;
}


