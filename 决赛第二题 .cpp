#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define pi 3.14

int main(){
	int N;
	cin>>N;
	vector<double> result;
	for(int i=0;i<N;i++){
		string s;
		cin>>s;
		if(s=="Cu"){
			double a,b,c,area;
			cin>>a>>b>>c;
			area = a*b*c;
			result.push_back(area);
		}
		if(s=="Sp"){
			double a,area;
			cin>>a;
			area = 4.0*pi*a*a*a/3.0;
			result.push_back(area);
		}
		if(s=="Cy"){
			double a,b,area;
			cin>>a>>b;
			area = a*a*pi*b;
			result.push_back(area);
		}
	}
	sort(result.begin(),result.end());
	for(int i=N-1;i>0;i--)
		cout<<fixed<<setprecision(2)<<result[i]<<" ";
	cout<<result[0];
	return 0;
}
