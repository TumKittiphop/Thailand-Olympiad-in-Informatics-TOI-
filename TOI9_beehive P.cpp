#include<bits/stdc++.h>
using namespace std;
int N,M;
unsigned long long Ans = 0;
unsigned long long A[1005][1005];
unsigned long long mem[1005][1005];
unsigned long long way[1005][1005];

unsigned long long dfs(int x,int y){
    if(y<0 ||y>=M)return 0;
    if(x==N-1)return A[x][y];
    if(mem[x][y]>0)return mem[x][y];
    //cout<<x;
    if(x%2==0){
        unsigned long long leftt = dfs(x+1,y-1);
        unsigned long long rightt = dfs(x+1,y);
        if(leftt==rightt){
            way[x][y] = way[x+1][y-1] + way[x+1][y];
        }
        else{
            if(leftt>rightt) way[x][y] = way[x+1][y-1];
            else way[x][y] = way[x+1][y];
        }
        mem[x][y] = max(leftt,rightt)+A[x][y];
        //cout<<mem[x][y]<<" "<<leftt<<" "<<rightt<<endl;
    }
    else{
        unsigned long long leftt = dfs(x+1,y);
        unsigned long long rightt = dfs(x+1,y+1);
        if(leftt==rightt){
            way[x][y] = way[x+1][y]+way[x+1][y+1];
        }
        else{
            if(leftt>rightt) way[x][y] = way[x+1][y];
            else way[x][y] = way[x+1][y+1];
        }
        mem[x][y] = max(leftt,rightt)+A[x][y];

        //cout<<mem[x][y]<<" "<<leftt<<" "<<rightt<<endl;
    }
    return mem[x][y];
}
int main(){
    cin>>N>>M;
//    for(int i=0;i<N;i++){
//        if(i%2==0){
//            for(int j=0;j<M;j++){
//                scanf("%d",&A[i][j]);
//                mem[i][j] =-1;
//            }A[i][M] = -1;
//            mem[i][M] = -1;
//        }
//        else{
//            A[i][0] = -1;
//            mem[i][0] = -1;
//            for(int j=1;j<=M;j++){
//                scanf("%d",&A[i][j]);
//                mem[i][j] = -1;
//            }
//        }
//    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            scanf("%llu",&A[i][j]);
            mem[i][j] =0;
        }
    }
    for(int i=0;i<M;i++){
        mem[N-1][i] = A[N-1][i];
        way[N-1][i] = 1;
    }
//    for(int i=0;i<N;i++){
//        for(int j=0;j<=M;j++){
//            printf("%d ",A[i][j]);
//        }printf("\n");
//    }
    unsigned long long cou=0;
    for(int i=0;i<M;i++){
        if(dfs(0,i)>Ans){
            Ans = dfs(0,i);
        }
    }
    for(int i=0;i<M;i++){
        if(mem[0][i] == Ans)cou+=way[0][i];
    }
    printf("%llu %llu",Ans,cou);
//    for(int i=0;i<N;i++){
//        for(int j=0;j<M;j++){
//            printf("%d ",mem[i][j]);
//        }printf("\n");
//    }

}
