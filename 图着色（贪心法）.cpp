#include <iostream>
#include <string>

using namespace std;

int color[100]; 
int arc[100][100];   //���ͼ�б�þ���
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
	int flag=1;   //��ʾͼ�л���û��Ⱦɫ�ı�
	while(flag==1){
		k++;
		flag=0;
		
		for(int i=0;i<n;i++){
		
			if(color[i]==0){
				color[i]=k;        //����iͿ��ɫk  
				if(!OK(i)){        //������ͻȡ����ɫ 
					color[i]=0;
					flag=1;
				}
			}
		} 
	} 
} 

int main(){
	int m;
	cout<<"�������ĸ����ͱߵ�������";
	cin>>n>>m; 
    
    //�����
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
    //������
	for(int i=0;i<n;i++){
		cout<<color[i]<<" ";
	} 
	return 0;
}


