#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
int N,M,x;
int v[6000005],qsum[6000005];

int main(){
    scanf("%d %d",&N,&M);
    priority_queue<ii> pq;
    v[0] = 0;
    qsum[0]=0;
    bool ch = false;
    for(int i=1;i<=N;i++){
        scanf("%d",&v[i]);
        qsum[i]= qsum[i-1]+v[i];
        if(v[i]>0)ch = true;
    }
    if(!ch){
        printf("0\n0");
        return 0;
    }
    //for(int i=0;i<=N;i++)cout<<qsum[i];
    for(int i=1;i<M;i++){
        pq.push({qsum[i],i});
        //cout<<qsum[i];
    }
    int Ans = INT_MIN;
    int siAns = INT_MAX;
    for(int i=1;i<=N;i++){
        if(i+M-1<=N)pq.push({qsum[i+M-1],i+M-1});
        while(pq.top().second<i &&!pq.empty()){
            pq.pop();
        }
        int f = pq.top().first;
        int s = pq.top().second;
        int si = s - i +1;
        int sum = f - qsum[i-1];
        if(sum>Ans){
            Ans = sum;
            siAns = si;
            continue;
        }
        if(sum==Ans){
            if(si<siAns)siAns = si;
        }
    }
    if(Ans<=0){
        printf("0\n0");
        return 0;
    }
    printf("%d\n%d",Ans,siAns);
}
