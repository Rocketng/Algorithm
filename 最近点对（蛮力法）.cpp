#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
struct point{
	double x;
	double y;
};

double Distance(point A,point B){
	return sqrt(pow((A.x-B.x),2)+pow((A.y-B.y),2)); 
}

int main(){
	int N;
	cin>>N;
	point P[N];
	for(int i=0;i<N;i++){
		cin>>P[i].x>>P[i].y;
	} 
	double dis=0x3fff;
	for(int i=0;i<N;i++){
		for(int j=i+1;j<N;j++)
		{
			if(Distance(P[i],P[j])<dis){
				dis=Distance(P[i],P[j]);
			}
		}
	}
	cout<<dis<<endl;

	return 0;
} 
