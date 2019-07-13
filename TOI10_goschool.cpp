#include<bits/stdc++.h>
using namespace std;
bool A[55][55];
long long dp[55][55];
int M,N,a,b,K;
int main(){
    scanf("%d%d",&M,&N);
    scanf("%d",&K);
    for(int i=0;i<K;i++){
        scanf("%d%d",&a,&b);
        A[b][a] = -1;
    }
//    for(int i=1;i<=N;i++){
//        for(int j=1;j<=M;j++){
//            printf("%d ",A[i][j]);
//        }cout<<endl;
//    }
    if(A[1][1]==1||A[N][M]==1){
        printf("0");
        return 0;
    }
    dp[1][1]=1;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(A[i][j]==1){
                continue;
            }
            if(A[i][j-1]!=1){
                dp[i][j] += dp[i][j-1];
            }
            if(A[i-1][j]!=1){
                dp[i][j] += dp[i-1][j];
            }
        }
    }
//    for(int i=1;i<=N;i++){
//        for(int j=1;j<=M;j++){
//            printf("%d ",dp[i][j]);
//        }cout<<endl;
//    }
    printf("%lld",dp[N][M]);
}

