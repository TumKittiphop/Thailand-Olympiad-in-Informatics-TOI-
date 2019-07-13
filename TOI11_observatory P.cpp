#include<bits/stdc++.h>
using namespace std;
int N,M,k;
int A[2005][2005],dpl[2005][2005],dpr[2005][2005],dp[2005][2005];
int main(){
    scanf("%d %d %d",&N,&M,&k);
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            scanf("%d",&A[i][j]);
            dp[i][j] = dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+A[i][j];
        }
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            dpl[i][j] = dpl[i-1][j-1]+ dp[i][j] - dp[i-1][j] ;
        }
    }
    for(int i=1;i<=N;i++){
        for(int j=M;j>=1;j--){
            dpr[i][j] = dpr[i-1][j+1] + dp[i][M] - dp[i][j-1] - (dp[i-1][M] - dp[i-1][j-1]);
        }
    }
//    for(int i=1;i<=N;i++){
//        for(int j=1;j<=M;j++){
//            printf("%d ",dpl[i][j]);
//        }cout<<endl;
//    }
    int Ans = INT_MIN;
    for(int i=k;i<=N;i++){
        for(int j=1;j<=M-(k-1);j++){
            int now  = dpr[i][j] - dpr[i-k][j+k] - (dp[i][M] - dp[i][j+k-1] - dp[i-k][M] + dp[i-k][j+k-1]);
            Ans = max(Ans,now);
        }
    }
    for(int i=k;i<=N;i++){
        for(int j=k;j<=M;j++){
            int now = dpl[i][j] -dpl[i-k][j-k] - (dp[i][j-k] - dp[i-k][j-k]);
            Ans = max(Ans,now);
        }
    }
    printf("%d",Ans);

}
