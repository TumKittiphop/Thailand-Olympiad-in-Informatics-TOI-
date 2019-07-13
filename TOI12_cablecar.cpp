#include<bits/stdc++.h>
using namespace std;
struct t{
    int now,dist;
    bool operator<(t T)const{
        return T.dist>dist;
    }
};
vector<pair<int,int>> adj[2505];
priority_queue<t> pq;
bool visited[2505];
int V,E,u,v,w,S,T,peo;
int main(){
    scanf("%d%d",&V,&E);
    for(int i=0;i<E;i++){
        scanf("%d%d%d",&u,&v,&w);
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    scanf("%d%d%d",&S,&T,&peo);
    pq.push({S,INT_MAX});
    int Min = INT_MAX;
    while(!pq.empty()){
        int now=pq.top().now;
        int d = pq.top().dist;
        pq.pop();
        if(visited[now])continue;
        visited[now]=1;
        Min = min(Min,d);
        if(now==T){
            Min--;
            //printf("A %d\n",Min);
            if(peo%Min==0){
                printf("%d",peo/Min);
            }
            else{
                printf("%d",(peo/Min)+1);
            }return 0;
        }
        for(int i=0;i<adj[now].size();i++){
            pq.push({adj[now][i].first,adj[now][i].second});
        }
    }
}
