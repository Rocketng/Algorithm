#include <iostream>
#include <cstring>

using namespace std;

int next[100];
char S[100];
char T[100];

void getnext(char a[]){
	int i,j,len;
	next[0]=-1;
	for(i=1;a[i]!='\0';i++){   //������next[i] 
		for(len=i-1;len>=1;len--){               //����Ӵ�����󳤶�Ϊi-1 
			for(j=0;j<len;j++){
				if(a[j]!=a[i-len+j])
				break;
			}
			
			if(j==len){
				next[j]=len;
				break;
			}
		}
		
		if(len<1)
		next[i]=0;     //���������������Ӵ� 
	}
} 

int KMP(char S[],char T[]){
	int i=0;
	int j=0;
	getnext(T);
	while(S[i]!='\0'&&T[j]!='\0'){
		if(S[i]==T[j]){
			i++;
			j++;
		}else{
			j=next[j];
			if(j==-1){
				i++;
				j++;
			}
		}
	}
	
	//���سɹ�ƥ��Ŀ�ʼλ�� 
	if(T[j]=='\0')
	return (i-strlen(T)+1);
	else
	return 0; 
} 

int main(){
	cout<<"�����������ַ�����"<<endl;
	gets(S);
	gets(T);
	cout<<KMP(S,T)<<endl;
	return 0;
}
