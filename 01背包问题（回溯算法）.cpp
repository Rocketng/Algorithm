#include <iostream>
using namespace std;
int Path[100];
void func(int weight[],int value[],int W,int n,int path[],int &Max,int V,int c,int start){
	if(c<=W){
		//Max=max(Max,V);
		if(V>Max){
			Max=V;
			for(int i=0;i<n;i++)
			Path[i]=path[i];      //������·�� 
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
	cout<<"��������Ʒ������";
	cin>>n;
	
	int weight[n],value[n];
	
	int path[n]={0};//������¼ȡ���ֵʱ����������Ʒ 
	
	cout<<"����������"<<n<<"����Ʒ�������ͼ�ֵ��"<<endl;
	for(int i=0;i<n;i++){
		cin>>weight[i]>>value[i]; 
	} 
	cout<<"�����뱳��������";
	cin>>W; 
	int Max=0;
	func(weight,value,W,n,path,Max,0,0,0);
	cout<<"������װ����ֵ:"<<Max<<endl;
	cout<<"��Ʒ������飺"<<endl;
	for(int i=0;i<n;i++)
	cout<<Path[i]<<" "; 
	return 0;
} 
