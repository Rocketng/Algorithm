#include <iostream>
using namespace std;
typedef struct{
	int weight;
	int lchild,rchild;
	int parent;   
}HTNode; 
typedef struct{
	HTNode *HTree;       //��̬��������洢���ڵ� 
	int root;            //���ڵ�λ�� 
}HuffmanTree;

void Select(HTNode* HT,int end,int *order_1,int* order_2){
	HTNode p;
	int i,count;
	int n,m,tmp;
	
	if(end<2)
	return;
	
	for(i=0,count=1;i<=end;i++){ //�����ҳ�����δ�������Ľڵ� 
		if(HT[i].parent==0){
			if(count==1)
			m=i;
			if(count==2)
			n=i;
			count++;
		}
		
		if(count>2)
		break;
	}
	
	if(HT[m].weight>HT[n].weight){   //��m�ڵ��Ȩ��С��N�ڵ� 
		tmp=n;
		n=m;
		m=tmp;
	} 
	
	i=((m>n)?m:n)+1;
	while(i<=end){   //��������Ѱ�Ҹ�С����ǰ�Ľڵ� 
		if(HT[i].parent==0){
			if(HT[i].weight<HT[m].weight){
				n=m;
				m=i;
			}else{
				if(HT[i].weight>=HT[m].weight&&HT[i].weight<HT[n].weight)
				n=i;
			}
		}
		i++;
	} 
	
	*order_1=HT[m].weight<=HT[n].weight?m:n;
	*order_2=HT[m].weight<=HT[n].weight?n:m; 
	
	cout<<*order_1<<" "<<*order_2<<endl;
}

void CreateHuffmanTree(HuffmanTree &HT,int *w,int n){
	//w���n��Ȩֵ��������0������HuffmanTree
	cout<<"��������������"<<endl;
	if(n<=1)
	return;
	
	int m=2*n-1;
	HT.HTree=new HTNode[m];    //����˳��ռ�
	HTNode* p;
	int i;
	for(p=HT.HTree,i=0;i<n;i++,p++,++w){
	//	*p={*w,-1,-1};
		(*p).weight=*w;
		(*p).lchild=(*p).rchild=0;
		(*p).parent=0;
	}
	
	
	for(;i<m;i++,p++){
	//	*p={0,-1,-1};
		(*p).weight=0;
		(*p).lchild=(*p).rchild=0;
		(*p).parent=0;
	}
	
	
	for(i=n;i<m;i++){
		int s1,s2;
		Select(HT.HTree,i-1,&s1,&s2);
		
		HT.HTree[s1].parent=HT.HTree[s2].parent=i;
		
		HT.HTree[i].lchild=s1;
		HT.HTree[i].rchild=s2;
		HT.HTree[i].weight=HT.HTree[s1].weight+HT.HTree[s2].weight;
	} 
	HT.root=m-1;	 
} 

int main(){
	int a[10];
	for(int i=0;i<10;i++)
	cin>>a[i];
	
	HuffmanTree HT;
	CreateHuffmanTree(HT,a,10);
	
	cout<<"����������"<<endl; 
	for(int i=0;i<19;i++){
		cout<<HT.HTree[i].weight<<"  ";
	}
	
	return 0;
}
