#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct edge{
	int from,to,cost;
};
//edge es[1000];
int d[10001];
int V,E;

void shortest_path(int s,vector<edge>&es){
	for(int i=0;i<V;i++){
		d[i] = INT_MAX;
	}
	d[s] = 0;
	while(true){
		bool update =false;
		for(int i=0;i<E;i++){
			edge e=es[i];
			if(d[e.from]!=INT_MAX && d[e.to]>d[e.from]+e.cost){
				d[e.to] = d[e.from] +e.cost;
				update = true;
			}
		}
		if(!update)
		break;
	}
}

int main(){
	int N,f,t;
	cin>>N>>f>>t;
	int i=0;
	vector<edge> es;
	while(true){
		int a,b,c;
		cin>>a>>b>>c;
		if(a==-1&&b==-1&&c==-1)
		break;
		edge ea,eb;
		ea.from = a-1;
		ea.to = b-1;
		ea.cost = c;
		i++;
		eb.from = b-1;
		eb.to = a-1;
		eb.cost = c;
		i++;
		es.push_back(ea);
		es.push_back(eb);
	}
	V = N;
	E = i;
	shortest_path(f-1,es);
	cout<<d[t-1];
	return 0;
}
