#include<bits/stdc++.h>
using namespace std;
int N,M,k,Max;
int A[1005][1005];
int dp[1005][1005];
int main(){
    cin>>N>>M>>k;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            scanf("%d",&A[i][j]);
            dp[i][j] = dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+A[i][j];
        }
    }
    for(int i=k;i<=N;i++){
        for(int j=k;j<=M;j++){
            Max = max(Max,dp[i][j]-dp[i-k][j]-dp[i][j-k]+dp[i-k][j-k]);
        }
    }
    cout<<Max;
}
