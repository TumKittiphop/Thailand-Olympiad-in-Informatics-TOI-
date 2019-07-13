#include<bits/stdc++.h>
using namespace std;
int N,M,cou;
int dp[100][100];
bool ch[100][100];
bool t[100][100];
int A[100][100];
int h[] = {0,0,1,-1};
int k[] = {1,-1,0,0};
void bfs(int i,int j){
    t[i][j] =0;
    for(int a=0;a<4;a++){
        if(h[a]+i>0&&h[a]+i<=N&&k[a]+j>0&&k[a]+j<=M){
            if(t[h[a]+i][k[a]+j]==1){
                bfs(h[a]+i,k[a]+j);
            }
        }
    }
}
int main(){
   char x[100];
    scanf("%d %d",&M,&N);
    for(int i=1;i<=N;i++){
        scanf("%s",x);
        for(int j=1;j<=M;j++){
            if(x[j-1]=='T'){
                A[i][j] = 1;
            }
            if(x[j-1]=='P')ch[i][j] = 1;
            dp[i][j] = dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+A[i][j];
        }
    }
//    for(int i=1;i<=N;i++){
//        for(int j=1;j<=M;j++){
//            printf("%d ",dp[i][j]);
//        }printf("\n");
//    }
    int minn = INT_MAX;
    bool check = false;
    for(int x=N;x>=1;x--){
        for(int i=x;i<=N;i++){
            for(int j=x;j<=M;j++){
                //printf("%d %d\n",i,j);
                if(dp[i][j]-dp[i-x][j]-dp[i][j-x]+dp[i-x][j-x]!=0)continue;

                check = true;
                for(int a=0;a<=N;a++){
                    for(int b=0;b<=M;b++){
                        t[a][b] = ch[a][b];
                    }
                }
                cou =0;
                //printf("AA %d %d\n",i,j);
                for(int a=i-x+1;a<=i;a++){
                    for(int b=j-x+1;b<=j;b++){
                        if(t[a][b]==1){
                            //printf("%d %d\n",a,b);
                            bfs(a,b);
                            cou++;
                        }
                    }
                }
                minn = min(cou,minn);
            }
        }

        if(check){
            printf("%d %d",x*x,minn);
            return 0;
        }
    }
    printf("0 0");
}
