#include<bits/stdc++.h>
using namespace std;
bitset<2005> A[2005];
int N,M;
int sq,tri,dia;
int h[] = {0,0,1,-1};
int k[] = {1,-1,0,0};
void BFS(int x,int y){
    A[x][y] = 0;
    for(int i=0;i<4;i++){
        if(x+h[i]>=0&&x+h[i]<N&&y+k[i]>=0&&y+k[i]<M){
            if(A[x+h[i]][y+k[i]]==1)
            BFS(x+h[i],y+k[i]);
        }
    }
}
int main(){
    cin>>M>>N;
    bool s[10005];
    for(int i=0;i<N;i++){
        scanf("%s",s);
        for(int j=0;j<M;j++){
            A[i][j] = s[j]-'0';
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){

            if(A[i][j]==1){
                //right=1
                if(j+1<M&&A[i][j+1]==1){
                    if(i+1<N){
                        if(A[i+1][j]==1){
                            BFS(i,j);
                            sq++;
                        }
                        else{
                            BFS(i,j);
                            tri++;
                            //printf(" A %d %d\n",i,j);
                        }
                    }
                    continue;
                }
                //right=0
                if(j+1<M && A[i][j+1]==0){
                    //printf("X %d %d %c",i,j,A[i][j+1]);
                    if(A[i+1][j+1]==1&&A[i+1][j-1]==1){
                        int tx = i+1,ty=j-1;
                        while(tx+1<N&&ty-1>=0&&A[tx+1][ty-1]==1){
                            tx+=1;ty-=1;
                        }
                        //printf("A %d %d\n",tx,ty);
                        if(tx+1>N){
                            BFS(i,j);
                            tri++;
                            //printf(" B %d %d\n",i,j);
                        }
                        else if(A[tx+1][ty+1]==0){
                            BFS(i,j);
                            tri++;
                            //printf("C %d %d\n",i,j);
                        }
                        else{
                            dia++;
                            BFS(i,j);
                        }
                    }
                    else{
                        BFS(i,j);
                        tri++;
                        //printf("D %d %d\n",i,j);
                    }
                }
            }
        }

    }
//for(int i=0;i<N;i++){
//            for(int j=0;j<M;j++){
//                printf("%c",A[i][j]);
//            }cout<<endl;
//        }cout<<endl;
    printf("%d %d %d",sq,dia,tri);
}
