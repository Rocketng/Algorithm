#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int N;
	cin>>N;
	int code[N];
	int sum = 0;
	int cha = INT_MAX;
	int zuo = 0;
	int index = 0;
	for(int i=0;i<N;i++){
		cin>>code[i];
		sum += code[i];
	}
	for(int i=0;i<N;i++){
		zuo += code[i];
		if(abs(sum-zuo-zuo)<cha){
			cha = abs(sum-zuo-zuo);
			index = i;
		}
	}
	cout<<index+1;
	
	return 0;
}
