#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int K;
	cin>>K;
	
	 int count=0;
    long long i=5;
    while(count<K){
    	if((int)log(i)/log(5))
        count+=(int)log(i)/log(5);
        
        i+=5;
    }
    if(count==K)
        cout<<5;
    else
        cout<<0;
        
    return 0;
}
