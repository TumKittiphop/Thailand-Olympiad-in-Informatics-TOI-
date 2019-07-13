#include<bits/stdc++.h>
using namespace std;
int A[105][105][4];
int dp[105][105];
struct t{
    int x,y,val;
};
int h[]={-1,0,1,0};
int k[]={0,1,0,-1};
int N,M;
char c[5];
int main(){
    scanf("%d%d",&N,&M);
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            scanf("%s",&c);
            if(c[0]=='B'){
                A[i][j][1] = 1;
                A[i][j][2] = 1;
                A[i+1][j][0]  = 1;
                A[i][j+1][3] = 1;
            }
            else if(c[0]=='D'){
                A[i][j][2] = 1;
                A[i+1][j][0] =1;
            }
            else if(c[0]=='R'){
                A[i][j][1] = 1;
                A[i][j+1][3] = 1;
            }
            dp[i][j] = INT_MAX;
        }
    }
    queue<t> q;
    q.push({1,1,1});
    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        int val = q.front().val;
        q.pop();
        //printf("%d %d %d\n",x,y,val);
        if(dp[x][y]==val &&val!=0){
            printf("%d\n%d %d",val,x,y);
            return 0;
        }

        if(dp[x][y]<val)continue;
        dp[x][y] = val;

        for(int i=0;i<4;i++){
            if(x+h[i]>0&&x+h[i]<=N &&y+k[i]>0&&y+k[i]<=M){
                if(A[x][y][i]==1){
                    q.push({x+h[i],y+k[i],val+1});
                }
            }
        }
    }
}
