#include <iostream>
using namespace std;

void  digui_search(int min,int max,int a[],int low,int high){
	int mid;
	min=(low+high)/2;
	if(a[mid]<min)
	digui_search(min,max,a,mid,high);
	else if(a[mid]>max)
	digui_search(min,max,a,low,mid);
	else{
		for(int i=mid;a[i]>=min&&i>=low;i--){
			cout<<a[i]<<" ";
		}
		cout<<endl;
		for(int j=mid+1;a[j]<=max&&j<=high;j++){
			cout<<a[j]<<" ";
		}
		cout<<endl;
	}
}

int main(){
	int r[6],min,max;
	cout<<"����������Ԫ�أ�"<<endl;
	for(int i=0;i<6;i++){
		cin>>r[i];
	} 
	cout<<"��������ҷ�Χ��Сֵmin�����ֵmax:";
	cin>>min>>max;
	digui_search(min,max,r,0,5); 
	return 0;
} 
