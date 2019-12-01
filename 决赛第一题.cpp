#include <iostream>
#include <string>
using namespace std;

int main(){
	string s;
	cin>>s;
	int len = s.size();
	for(int i=0;i<len;i++){
		if(s[i]=='0')
			s[i] = '3';
		else if (s[i]=='1')
			s[i] = '4';
		else if(s[i]=='2')
			s[i] = '5';
		else if(s[i]=='3')
			s[i] = '6';
		else if(s[i]=='4')
			s[i] = '7';
		else if(s[i]=='5')
			s[i] = '8';
		else if(s[i]=='6')
			s[i] = '9';
		else if(s[i]=='7')
			s[i] = '0';
		else if(s[i]=='8')
			s[i] = '1';  
		else if(s[i]=='9')
			s[i] = '2';
	}
	cout<<s;
	return 0;
} 
