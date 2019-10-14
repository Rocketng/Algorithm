#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
struct point{
	double x;
	double y;
};
bool comp1(point A,point B){
	return A.x<B.x;
}
bool comp2(point A,point B){
	return A.y<B.y;
}

double Distan(point A ,point B){
	return sqrt(pow((A.x-B.x),2)+pow((A.y-B.y),2));	
}

double megry(vector<point> P,double dis,double mid){
	vector<point> left,right;  //手机左右两边满足条件的点
	int n=P.size();
	for(int i=0;i<n;i++){
		if(P[i].x<=P[mid].x&&P[mid].x-P[i].x<=dis){
			left.push_back(P[i]);
		}
		if(P[i].x>P[mid].x&&P[i].x-P[mid].x<=dis){
			right.push_back(P[i]);
		}
	} 
	sort(right.begin(),right.end(),comp2);
	for(int i=0,index;i<left.size();i++){
		for(index=0;index<right.size()&&left[i].y<right[index].y;index++);
		
		for (int j = 0; j < 7 && index + j < right.size(); ++j)  // 遍历右边坐标上界的6个点
		{
			if (Distan(left[i], right[j + index]) < dis)
				dis = Distan(left[i], right[j + index]);
		}
	}
	return dis;
}

double close(vector<point> P){
	int n=P.size();
	if(n<=0){
		return 0;
	}else if(n==2){
		return Distan(P[0],P[1]);
	}
	else if(n==3){
		return min(Distan(P[1],P[2]),min(Distan(P[0],P[1]),Distan(P[0],P[2])));
	}else{
		int mid=(n>>1)-1;
		vector<point> left(mid+1),right(P.size()-mid-1);
		copy(P.begin(),P.begin()+mid+1,left.begin());
		copy(P.begin()+mid+1,P.end(),right.begin());
		double d1=close(left);
		double d2=close(right);
		double dis=min(d1,d2);
		return megry(P,dis,mid);
	}
}

int main(){
	int N;
	cout<<"请输入点数：";
	cin>>N;
	vector<point> P;
	cout<<"请依次输入每个点的横纵坐标：";
	for(int i=0;i<N;i++){
		point a;
		cin>>a.x>>a.y;
		P.push_back(a);
	}
	sort(P.begin(),P.end(),comp1);
	
	cout<<"结果为："<<close(P)<<endl;
	
	return 0;
}
