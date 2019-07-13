#include<bits/stdc++.h>
using namespace std;
vector<int> v[500005];
int N,st;
bool visited[500005];
int dp[500005];
int dfs(int now,int pre){//printf("%d\n",now);
    if(now==st)return -1;
    if(visited[now])return 0;
    visited[now] = 1;

    if(v[now].size()==1){
        return 1;
    }
    int sum=0;
    dp[now] = sum;
    bool ch = false;
    for(int i=0;i<v[now].size();i++){
        if(v[now][i]==pre)continue;
        int t = dfs(v[now][i],now);
        if(t==-1){
            ch = true;
            //ch = false;
        }
        else{
            sum+=t;
        }
    }
    dp[now] = sum;
    if(ch==true){
        return -1;
    }
    else{
        return sum+1;
    }
    //dp[now] = sum;
    //return 1+sum;
}
int main(){
    int x,y;
    scanf("%d %d",&N,&st);
    for(int i=0;i<N;i++){
        scanf("%d %d",&x,&y);
        v[y].push_back(x);
        v[x].push_back(y);
    }

    for(int i=0;i<v[st].size();i++){
       dfs(v[st][i],st);
        //printf("%d %d\n",v[st][i],t);

        //Max = max(Max,dfs(v[st][i],st));
    } int Max = INT_MIN,idx=INT_MAX;
    for(int i=1;i<=N;i++){
        //cout<<dp[i]<<endl;
        if(i==st)continue;
        if(dp[i]>Max){
            Max = dp[i];
            idx  = i;
        }if(dp[i]==Max)idx = min(idx,i);
        //Max = max(Max,dp[i]);

    }
    printf("%d\n%d",idx,Max);
}
