#include<bits/stdc++.h>
using namespace std;
int N,M,tx,ty;
int A[98][101];
bitset<2500> chk[105][105];
int ex[]={0,0,1,1,-1,-1};
int ey[]={1,-1,0,1,0,1};
int ox[]={0,0,1,1,-1,-1};
int oy[]={1,-1,-1,0,-1,0};
struct t{
    int xx,yy,ti;
};
int main(){
    ios_base::sync_with_stdio(false);
    scanf("%d %d",&M,&N);
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            scanf("%d",&A[i][j]);
        }
    }
    int eny = N-1;
    int enx = (M-1)/2;
    queue<t> q;
    if(A[enx][0]==1)
    q.push({enx,0,1});
    if(A[enx+1][0]==1)
    q.push({enx+1,0,1});
    if(A[enx-1][0]==1)
    q.push({enx-1,0,1});
    while(!q.empty()){
        int x = q.front().xx;
        int y = q.front().yy;
        int ti = q.front().ti;
        //cout<<x<<" "<<y<<" "<<ti<<endl;
        q.pop();
        //if(A[x][y]==0)continue;
        if(ti>=5000)continue;
        if(x==enx&&y==eny){
            printf("%d",ti);
            return 0;
        }
        if(x%2==0){
            for(size_t i=0;i<6;i++){
                tx = x+ex[i],ty = y+ey[i];
                if(tx<0||tx>=M ||ty<0||ty>=N)continue;
                    if(A[tx][ty]==0)continue;
                    if(chk[tx][ty][ti+1]==1)continue;
                    chk[tx][ty][ti+1] = 1;
                    if((ti+1)%(A[tx][ty])!=0)continue;
                    q.push({tx,ty,ti+1});

            }
        }
        else{
            for(size_t i=0;i<6;i++){
                tx = x+ox[i],ty = y+oy[i];
                if(tx<0||tx>=M||ty<0||ty>=N)continue;
                    if(A[tx][ty]==0)continue;
                    if(chk[tx][ty][ti+1]==1)continue;
                    chk[tx][ty][ti+1] = 1;
                    if((ti+1)%(A[tx][ty])!=0)continue;
                    q.push({tx,ty,ti+1});

            }
        }
    }
}
