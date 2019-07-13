#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> adj[105];
//now,fuel,card
int mem[105][105][2];
struct t{
    int now,fuel,val,card;
    bool operator<(t T)const{
        return T.val < val;
    }
};
int V,E,u,v,w,S,T,Tank;

int Price[105];
int main(){
    scanf("%d",&V);
    for(int i=1;i<=V;i++){
        scanf("%d",&Price[i]);
    }
    scanf("%d%d%d",&S,&T,&Tank);
    scanf("%d",&E);
    for(int i=0;i<E;i++){
        scanf("%d%d%d",&u,&v,&w);
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    for(int i=0;i<105;i++){
        for(int j=0;j<105;j++){
            for(int k=0;k<2;k++)mem[i][j][k] = INT_MAX;
        }
    }
    priority_queue<t> pq;
    pq.push({S,0,0,0});
    mem[S][0][0] =0;
    while(!pq.empty()){
        int now = pq.top().now;
        int fuel = pq.top().fuel;
        int val = pq.top().val;
        int card = pq.top().card;
        pq.pop();
        if(mem[now][fuel][card]<val)continue;
        mem[now][fuel][card]=val;
        if(now==T && fuel==Tank){
            printf("%d",val);
            return 0;
        }
        if(card==0 && fuel!=Tank && mem[now][Tank][1]>val){
            pq.push({now,Tank,val,1});
        }
//        if(now==T){
//            pq.push({now,fuel+1,val+Price[now],card});
//        }

        if(fuel<Tank && mem[now][fuel+1][card]>val){
            pq.push({now,fuel+1,val+Price[now],card});
        }

        for(int i=0;i<adj[now].size();i++){
            int w = adj[now][i].second;
            if(fuel>=w && mem[adj[now][i].first][fuel-w][card]>val){
                pq.push({adj[now][i].first,fuel-w,val,card});
            }
        }

    }
}
