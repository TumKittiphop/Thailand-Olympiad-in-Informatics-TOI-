#include<bits/stdc++.h>
using namespace std;
int N,M;
int A[320][320];
int Pipe[320][320];

int DFS(int x,int y,int be){
    if(x<0||x>=N||y<0||y>=M)return 0;
    Pipe[x][y]--;
    //cout<<A[x][y]<<endl;
    if(A[x][y]==21){
        if(be ==2){
            return 1+DFS(x+1,y,2);
        }
        else{
            return 1+DFS(x-1,y,0);
        }
    }
    if(A[x][y]==22){
        if(be==3){
            return 1+DFS(x,y-1,3);
        }
        else{
            return 1+DFS(x,y+1,1);
        }
    }

    if(A[x][y]==11){
        if(be==2){
            return 1+DFS(x,y-1,3);
        }
        else{
            return 1+DFS(x-1,y,0);
        }
    }
    if(A[x][y]==12){
        if(be==2){
            return 1+DFS(x,y+1,1);
        }
        else{
            return 1+DFS(x-1,y,0);
        }
    }
    if(A[x][y]==13){
        if(be==1){
            return 1+DFS(x+1,y,2);
        }
        else{
            return 1+DFS(x,y-1,3);
        }
    }
    if(A[x][y]==14){
        if(be==3){
            return 1+DFS(x+1,y,2);
        }
        else{
            return 1+DFS(x,y+1,1);
        }
    }
    if(A[x][y]==31){
        if(be==1){
            return 1+DFS(x,y+1,1);
        }
        else if(be==2){
            return 1+DFS(x+1,y,2);
        }
        else if(be==3){
            return 1+DFS(x,y-1,3);
        }
        else{
            return 1+DFS(x-1,y,0);
        }
    }
}
int main(){
    scanf("%d %d",&N,&M);
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>A[i][j];
            if(A[i][j]!=0&&A[i][j]!=31){
                Pipe[i][j] = 1;
            }
            else if(A[i][j]==31){
                Pipe[i][j]=2;
            }
            else{
                Pipe[i][j]=0;
            }
        }
    }
//    for(int i=0;i<N;i++){
//        for(int j=0;j<M;j++){
//            printf("%d ",Pipe[i][j]);
//        }cout<<endl;
//    }
    vector<int> v;
    for(int i=0;i<N;i++){
        if(A[i][0]!=11 && A[i][0]!=13 && A[i][0]!=22 && A[i][0]!=31){
            continue;
        }
        if(Pipe[i][0]!=0){
            v.push_back(DFS(i,0,1));
        }
    }

    for(int j=0;j<M;j++){
        if(A[0][j]!=12 && A[0][j]!=11 && A[0][j]!=21 && A[0][j]!=31){
            continue;
        }
        if(Pipe[0][j]!=0){

            v.push_back(DFS(0,j,2));
        }
    }
    for(int i=0;i<N;i++){
        if(A[i][M-1]!=12 && A[i][M-1]!=14 && A[i][M-1]!=22 && A[i][M-1]!=31){
            continue;
        }
        if(Pipe[i][M-1]!=0){
            v.push_back(DFS(i,M-1,3));
        }
    }
    for(int j=0;j<M;j++){
        if(A[N-1][j]!=13 && A[N-1][j]!=14 && A[N-1][j]!=21 && A[N-1][j]!=31){
            continue;
        }
        if(Pipe[N-1][j]!=0){
            v.push_back(DFS(N-1,j,0));
        }
    }
    if(v.size()==0){
        cout<<0<<endl;
        return 0;
    }
    cout<<v.size()<<endl;
    for(int i=0;i<v.size();i++){
        printf("%d ",v[i]);
    }
}
