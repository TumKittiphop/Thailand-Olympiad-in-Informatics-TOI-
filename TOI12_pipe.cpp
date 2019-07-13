#include<bits/stdc++.h>
using namespace std;
map<pair<int,int> ,int> ma;
pair<int,int> Loca[20000];
int par[20000],high[20000];
int dis(int x,int y,int x1,int y1){
    return abs(x-x1)+abs(y-y1);
}
struct t{
    int u,v,w;
    bool operator<(t T)const{
        return T.w<w;
    }
};

int N,k;
int f(int x){
    if(par[x]!=x){
        par[x] = f(par[x]);
    }
    return par[x];
}
void un(int x,int y){
    x = f(x),y=f(y);
    if(high[x]>high[y]){
        par[y] =x;
    }
    else{
        par[x] =y;
    }
    if(high[x]==high[y])high[x]++;
}

int main(){
    int sum=0;
    int a,b;
    scanf("%d %d",&N,&k);
    for(int i=0;i<N;i++){
        scanf("%d %d",&a,&b);
        Loca[i].first=a;
        Loca[i].second=b;
        par[i] = i;
        high[i] =0;
    }
    priority_queue<t> pq;
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            if(i==j)continue;
            int dd = dis(Loca[i].first, Loca[i].second, Loca[j].first, Loca[j].second);

            pq.push({i,j,dd});
        }
    }

    int c=0;
    priority_queue<int> re;
    while(c!=N-1&&!pq.empty()){
        int u = pq.top().u;
        int v = pq.top().v;
        int w = pq.top().w;

        pq.pop();
        u = f(u);
        v = f(v);
        //cout<<u<<v<<w<<endl;
        if(u!=v){
            un(u,v);
            sum+=w;
            re.push(w);
            c++;
        }
    }
    k--;
    if(k>=N){
        cout<<0;
        return 0;
    }
    for(int i=0;i<k;i++){
        if(re.empty())break;
        sum-=re.top();
        re.pop();
    }
    cout<<sum;
}
