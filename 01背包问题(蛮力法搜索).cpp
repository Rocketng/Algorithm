#include <iostream>
using namespace std;
int weight[100],value[100];		//��Ʒ�����ͼ�ֵ 
int Path[100],path[100];        //����·�����뵱ǰ·�� 
int W;   		//�������� 
int N;    		//��Ʒ���� 
int Max;        //����ֵ 
int V;          //��ǰ��ֵ 
int w;          //��ǰ���� 

int func(int i){
	if(i>=N){
		if(V>Max&&w+value[i]<=W){
			Max=V;
			for(int i=0;i<N;i++)
			Path[i]=path[i];
		} 
		return Max;
	}
	
	//���뱳�� 
	w+=weight[i];
	V+=value[i];
	path[i]=1;
	func(i+1);

    //�����뱳�� 
	w-=weight[i];
	V-=value[i];
	path[i]=0;
	func(i+1);
	return Max;
}

int main(){
	cout<<"��������Ʒ������";
	cin>>N;
	
	cout<<"�����뱳��������";
	cin>>W;
	
	cout<<"����������ÿ����Ʒ�������ͼ�ֵ:"<<endl;
	for(int i=0;i<N;i++)
	cin>>weight[i]>>value[i]; 
	
	cout<<"����ֵ��"<<func(0)<<endl;
	cout<<"��Ʒ�������:"<<endl;
	for(int i=0;i<N;i++)
	cout<<Path[i]<<" "; 
	return 0; 
} 
