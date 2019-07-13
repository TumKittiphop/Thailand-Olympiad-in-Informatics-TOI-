#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
ii dp[1005][1005];
int A1[1005],A2[1005];
int Max,N;
ii f(ii a,int b){
    if(a.second+b>Max){
        return {a.first+1,b};
    }
    return {a.first,a.second+b};
}
int main(){
    cin>>Max>>N;
    dp[0][0] = {0,0};
    for(int i=1;i<=N;i++){
        cin>>A1[i];
        dp[0][i] = f(dp[0][i-1],A1[i]);
    }
    for(int i=1;i<=N;i++){
        cin>>A2[i];
        dp[i][0] = f(dp[i-1][0],A2[i]);
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            ii a = f(dp[i-1][j],A2[i]);
            ii b = f(dp[i][j-1],A1[j]);
            if(a.first==b.first){
                if(a.second>b.second)dp[i][j] = b;
                else dp[i][j]  =a;
            }
            else{
                if(a.first>b.first){
                    dp[i][j] = b;
                }
                else{
                    dp[i][j] = a;
                }
            }
        }
    }


    printf("%d\n%d",dp[N][N].first+1,dp[N][N].second);
}
