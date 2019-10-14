#include <iostream>
#include <string>
using namespace std;
string path; 
int func(string str1,string str2){
	int m=str1.size();
	int n=str2.size();
	
	int Dp[m+1][n+1];
	int S[m+1][n+1];
	
	for(int i=0;i<=m;i++)
	Dp[i][0]=0;
	for(int i=0;i<=n;i++)
	Dp[0][i]=0;
	
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(str1[i-1]==str2[j-1]){
				Dp[i][j]=Dp[i-1][j-1]+1;
			    S[i][j]=1;
			}else if(Dp[i-1][j]>Dp[i][j-1]){
				Dp[i][j]=Dp[i-1][j];
				S[i][j]=3;
			}else{
				Dp[i][j]=Dp[i][j-1];
				S[i][j]=2;
			}
		}
	}
    
    for(int i=1;i<=m;i++){
    	for(int j=1;j<=n;j++)
    	cout<<S[i][j]<<" ";
    	cout<<endl;
	}
    
    int i=m,j=n;
    while(i>0&&j>0){
    	if(S[i][j]==1){
    		cout<<str1[i-1]; 
    		path=str1[i-1]+path;
    		i--;
    		j--;
		}else if(S[i][j]==2){
			j--;
		}else{
			i--;
		}
	}
	
	//输出路径
	cout<<"子序列："<<path<<endl; 
    
	return Dp[m][n];
}

int main(){
	string str1,str2;
	cout<<"请输入两个字符串:";
	cin>>str1>>str2;
	cout<<"长度:"<<func(str1,str2)<<endl; 
	return 0;
} 

