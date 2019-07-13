#include<bits/stdc++.h>
using namespace std;
struct t{
    int sum,idx;
    bool operator<(t T)const{
        return T.sum<sum;
    }
};
int N,k,x;
priority_queue<t> pq;
int main(){
    scanf("%d %d",&N,&k);
    cin>>x;
    pq.push({x,1});
    for(int i=2;i<=N;i++){
        while(!pq.empty()&&i-pq.top().idx >k) pq.pop();
        cin>>x;

        int v = x+pq.top().sum;
        pq.push({v,i});
        if(i==N){
            printf("%d",v);
            return 0;
        }
    }
}
