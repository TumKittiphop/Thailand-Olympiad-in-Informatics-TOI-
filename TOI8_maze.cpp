#include<bits/stdc++.h>
using namespace std;
int dist[160][160];
int A[160][160];
struct t{
    int x,y,val;
};
bool visited[160][160];
bool vib[160][160];
bool vi[160][160];
int h[] = {0,0,1,-1};
int k[] = {1,-1,0,0};
int N,M,sx,sy,ex,ey;
int main(){
    scanf("%d%d",&N,&M);
    scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            scanf("%d",&A[i][j]);
            dist[i][j] = -1;
        }
    }
    queue<t> q;
    for(int i=0;i<4;i++){
            if(sx+h[i]>0 && sx+h[i]<=N &&sy+k[i]>0 &&sy+k[i]<=M){
                q.push({sx+h[i],sy+k[i],2});
            }
    }
    vi[sx][sy] = 1;
    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        int val = q.front().val;
        q.pop();
        if(vi[x][y])continue;
        vi[x][y] = 1;
        dist[x][y] = val;
        if(A[x][y]==0){
            continue;
        }
        else{
            vib[x][y] = 1;
        }

        for(int i=0;i<4;i++){
            if(x+h[i]>0 && x+h[i]<=N &&y+k[i]>0 &&y+k[i]<=M){
                q.push({x+h[i],y+k[i],val+1});
            }
        }
    }
//    for(int i=1;i<=N;i++){
//        for(int j=1;j<=M;j++){
//            printf("%d ",dist[i][j]);
//        }cout<<endl;
//    }
    queue<t> q2;
//    for(int i=0;i<4;i++){
//            if(ex+h[i]>0 && ex+h[i]<=N &&ey+k[i]>0 &&ey+k[i]<=M){
//                q2.push({ex+h[i],ey+k[i],1});
//            }
//    }
//    vib[ex][ey] = 1;
    q2.push({ex,ey,0});
    int Min=INT_MAX,sum=0;
    while(!q2.empty()){
        int x = q2.front().x;
        int y = q2.front().y;
        int val = q2.front().val;
        q2.pop();
        if(vib[x][y])continue;
        vib[x][y] = 1;
        if(A[x][y]==0 && dist[x][y]!=-1){
            sum++;
            Min = min(Min,dist[x][y]+val);
            continue;
        }
        if(A[x][y]==0)continue;
        for(int i=0;i<4;i++){
            if(x+h[i]>0 && x+h[i]<=N &&y+k[i]>0 &&y+k[i]<=M){
                q2.push({x+h[i],y+k[i],val+1});
            }
        }
    }
//    for(int i=1;i<=N;i++){
//        for(int j=1;j<=M;j++){
//            printf("%d ",visited[i][j]);
//        }cout<<endl;
//    }
    printf("%d\n%d",sum,Min);
}

