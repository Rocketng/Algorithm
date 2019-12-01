
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL inline f(LL x,LL m){
	LL ans=0;
	LL l=x;
	for(int i=0;i<m;++i){
		ans+=x;
		x=ceil(x/2.0);
	}
	return ans;
}

int main(){
	LL N,M;
	cin>>N>>M;
	LL left = 1,right = N,mid = N>>1;
	while(left < right){
		LL a= f(mid,M);
		if(a>N) right=mid;
		else if(a==N) left=right=mid;
		else{
			left=mid+1;
		}
		mid = (left+right)>>1;
	}
	cout<<left;
	return 0;
}

