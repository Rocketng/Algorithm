//���ݷ�-���ȶ��н�gԴ���·��
#include<iostream>
#include<algorithm>
#include<queue>
#define MAX 100
#define LIMITLESS 65535
using namespace std;
int cost[MAX];                 //Դ�㵽����ľ���
typedef struct{
    bool operator()(int &a,int &b){
         return cost[a]>cost[b];
    }
}cmp;
typedef struct Graph{
    int v,e;
    int vex[MAX];
    int wei[MAX][MAX];
}Graph,*graph;
void createGraph(graph g){
    cout<<"���붥��ͱ���:"<<endl;
    cin>>g->v>>g->e;
    cout<<"���붥��ֵ:"<<endl;
    for(int i = 1;i<=g->v;i++){
         cin>>g->vex[i];
    }
    for(int i = 1;i<=g->v;i++){          //ͼ��Ȩֵ��ʼ��
        for(int j = 1;j<=g->v;j++){
            g->wei[i][j] = LIMITLESS;
        }
    }
    cout<<"���������ӵ��±��Ȩֵ:"<<endl;
    int k1,k2,weight;
    for(int i = 1;i<=g->e;i++){
        cin>>k1>>k2>>weight;
        g->wei[k1][k2] = weight;
    }
}

void  dijkstra(graph g,int sour){
      cost[sour] = 0;
      for(int i = 2;i<=g->v;i++){                   //cost[i]��ʼ��ΪԴ�㵽�������Ȩֵ
          cost[i] = g->wei[sour][i];
      }
      priority_queue<int,vector<int>,cmp> p;      //���ȶ���
      p.push(sour);                              //Դ�������
      int flag [MAX];                           //����ĳ���˳��
      int k = 0;
      while(!p.empty()){
          int item = p.top();
          flag[k++] = item;
          p.pop();
          /*���������Ż�*/
          for(int i = item;i<=g->v;i++){
             if((g->wei[item][i]!=LIMITLESS)&&(cost[item]+g->wei[item][i]<=cost[i])){
                  cost[i] = cost[item]+g->wei[item][i];
                  p.push(i);
             }
          }
      }
      for(int i = 2;i<=g->v;i++){
          cout<<"Դ�㵽"<<i<<"�������̾���Ϊ:"<<cost[i]<<endl;
      }
      cout<<"����ĳ�����˳��(��Դ�㵽�������̵�����):"<<endl;
      for(int i = 0;i<k;i++){
          cout<<flag[i]<<" ";
      }
}
int main(){
     Graph g;               
     createGraph(&g);
     dijkstra(&g,1);
     return 0; 
}

