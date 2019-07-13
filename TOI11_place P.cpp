#include<bits/stdc++.h>
using namespace std;

long long par[200005],high[200005];
struct t{
    int u,v,w;
};
int f(int u){
    if(par[u]==u){
        return u;
    }
    return par[u]=f(par[u]);
}
bool com(const t &a,const t &b){
    return a.w > b.w;
}
int main(){
    int V,E,u,v,w,W;
    scanf("%d %d",&V,&E);
    for(int i=1;i<=V;i++){
        par[i] = i;
    }
    vector<t> pq;
    for(int i=0;i<E;i++){
        scanf("%d %d %d",&u,&v,&w);
        pq.push_back({u,v,w});
    }
    long long sum=0;
    int c=0;
    sort(pq.begin(),pq.end(),com);
    for(int i=0;i<pq.size();i++){
        int U = pq[i].u;
        int V = pq[i].v;
        U = f(U);V = f(V);
        if(U!=V){
            c++;
            sum+=(pq[i].w- 1);
            par[U]=V;
        }
        //cout<<c<<pq[i].w<<endl;
    }
    printf("%lld",sum);
}
