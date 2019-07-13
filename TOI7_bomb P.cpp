#include<bits/stdc++.h>
using namespace std;
int N,x,y;
struct t{
    int x,y;
    bool operator<(t T)const{
        if(T.x != x){
            return T.x>x;
        }
        else{
            return T.y<y;
        }
    }
};
vector<t > v;
priority_queue<pair<int,int>> pq;
int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++)scanf("%d %d",&x,&y),v.push_back({x,y});
    sort(v.begin(),v.end());
    for(int i=0;i<N;i++)pq.push({v[i].y,i});

    for(int i=0;i<N-1;i++){
        int F = v[i].y;

        while(pq.top().second<=i&&!pq.empty())pq.pop();

        if(pq.top().first<=F)printf("%d %d\n",v[i].x,F);
    }
    printf("%d %d",v[N-1].x,v[N-1].y);
}

