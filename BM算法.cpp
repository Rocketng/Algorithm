#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int bad[10005];
int stuff[10005];
int Gs[10005];

//���ַ����� 
void Badchar(string x)
{
	int i;
	int m=x.length();
	cout<<m<<endl;
	//ȫ�����������ڴ��� 
	for(i=0;i<256;i++)
	{
		bad[i]=m;
	}
	//��Ǵ��ڵ� 
	for(i=0;i<m-1;i++)
	{
		bad[x[i]]=m-i-1;
	}
	
	cout<<"���ַ���";
	for(i=0;i<m;i++)
	cout<<bad[x[i]]<<" ";
	cout<<endl;
}
//���׺��ͬ���ַ����ȣ���������� 
void getstuff(string &x)
{
	int i,j;
	int m=x.length();
	stuff[m-1]=m;
	for(i=m-2;i>=0;i--)
	{
		j=i;
		for(;j>=0&&x[j]==x[m-1-i+j];)
		j--;
		stuff[i]=i-j;
	}
	
	cout<<"��ͬ����";
	for(i=0;i<m;i++)
	cout<<stuff[i]<<" ";
	cout<<endl;
} 
//
void getGs(string &x)
{
	int i,j=0;
	int m=x.length();
	getstuff(x);
	//��һ����������ںú�׺
	 for(i=0;i<m;i++)
	 Gs[i]=m;
	//�ڶ�����������ڸ�ǰ׺ƥ��ĺú�׺
	for(i=m-1;i>=0;i--)
	{
		if(Gs[i]==m)
		{
			if(stuff[i]==i+1)
			for(;j<m-1-i;j++)
			Gs[j]=m-1-i;
		}
	 } 
	 //����������������Ӵ�����׺ƥ��
	 for(i=0;i<=m-2;i++)
	 {
	 	Gs[m-1-stuff[i]]=m-i-1;
	  } 
	  
	cout<<"�ú�׺��";
	for(i=0;i<m;i++)
	cout<<Gs[i]<<" ";
	cout<<endl;
} 
int BM(string &x,string &y)
{
	int m=x.length();
	int n=y.length();
	
	int i=0,j;
	while(i<=n-m)
	{
		for(j=m-1;j>=0;j--)
		{
			if(y[i+j]!=x[j])
				break;
		}	
		if(j<0)
		{
			return i;
		}
		else
		{
			i+=max(Gs[j],bad[y[i+j]]-m+1+j);
		}
	}
	return -1;
}
int main()
{
	string a,b;
	cin>>b>>a;
	Badchar(a);
	getGs(a);
	if(BM(a,b)<0)
	cout<<"Can't achieve!"<<endl;
	else
	cout<<BM(a,b)+1<<endl;
	return 0;
	
}















