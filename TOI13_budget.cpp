#include<bits/stdc++.h>
using namespace std;
struct t{
    int u;
    long long dist;
    bool operator<(t T)const{
        return T.dist<dist;
    }
};
int V,E,a,b,S,T;
long long w,poww;
vector<t> adj[10005];
long long distS[10005],distT[10005];
bool visitedS[10005],visitedT[10005];
int main(){
    scanf("%d %d",&V,&E);
    scanf("%d %d %lld",&S,&T,&poww);
    for(int i=0;i<E;i++){
        scanf("%d %d %lld",&a,&b,&w);
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }
    priority_queue<t> pqS,pqT;
    for(int i=0;i<=V;i++){
        distS[i] = LLONG_MAX;
        distT[i] = LLONG_MAX;
    }
    distS[S] = 0;
    pqS.push({S,0});
    while(!pqS.empty()){
        int u = pqS.top().u;
        pqS.pop();
//        if(visitedS[u])continue;
//        visitedS[u] = 1;
        for(int i=0;i<adj[u].size();i++){
            int v = adj[u][i].u;
            long long d = adj[u][i].dist;
            if(distS[v]>distS[u]+d){
                distS[v] = distS[u]+d;
                pqS.push({v,distS[v]});
            }
        }
    }
    if(distS[T]<=poww){
        printf("%d %lld 0",T,distS[T]);
        return 0;
    }
    distT[T] =0;
    pqT.push({T,0});
    while(!pqT.empty()){
        int u = pqT.top().u;
        pqT.pop();
//        if(visitedT[u])continue;
//        visitedT[u] = 1;
        for(int i=0;i<adj[u].size();i++){
            int v = adj[u][i].u;
            long long d = adj[u][i].dist;
            if(distT[v]>distT[u]+d){
                distT[v]=distT[u]+d;
                pqT.push({v,distT[v]});
            }
        }
    }
    long long Min = LLONG_MAX,distance;
    int idx = INT_MAX;
    for(int i=1;i<=V;i++){
        if(distT[i]<Min && distS[i]<=poww){
            Min = distT[i];
            distance = distS[i];
            idx = i;
        }
        if(distT[i]==Min && distS[i]<=poww){
            idx = min(idx,i);
        }
    }
    printf("%d %lld %lld",idx,distance,Min);
}
