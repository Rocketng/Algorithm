#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#define size 4
#define MAX 100
int b=1<<(size-1);
int c[size][size];
int Map[size][MAX];

void function(int num){
	for(int i=0;i<size;i++){
		Map[i][num]=0x7ffff;
		if((num>>(i-1))&1==1){
			continue;
		}
		
		for(int k=0;k<size;k++){
			//不能到达的城市
			if(((num>>(k-1))&1)==0){
				continue;
			} 
			if(Map[i][num]>Map[k][num^(1<<(k-1))]+c[i][k]){
				Map[i][num]=Map[k][num^(1<<(k-1))]+c[i][k];
			}
		}
	}
}

int main(){
	//初始化
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			cin>>c[i][j];
		}
	} 
	//城市间距离如下
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++)
		cout<<c[i][j]<<" ";
		cout<<endl;
	} 
	
	for(int i=0;i<size;i++){
		for(int j=0;j<pow(2,size-1);j++){
			Map[i][j]=-1;
		}
	}
	for(int i=0;i<size;i++){
		Map[i][0]=c[i][0];
	}
	
	for(int i=1;i<pow(2,size-1);i++){
		function(i);
	}
	
	int Min=Map[0][(int)(pow(2,size-1)-1)];
	for(int i=1;i<size;i++){
		if(Map[i][(int)(pow(2,size-1)-1)]<Min)
		Min=Map[i][(int)(pow(2,size-1)-1)];
	} 
	cout<<Min<<endl;
	return 0;
} 
