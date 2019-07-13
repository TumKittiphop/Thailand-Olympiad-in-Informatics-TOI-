#include<bits/stdc++.h>
using namespace std;
char s[2005];
char A[2005][2005];
int N,M;
struct t{
    int x,y,dist;
};
int h[] = {0,0,1,-1};
int k[] = {1,-1,0,0};
bool visited[2005][2005];
int main(){
    queue<t> q;
    scanf("%d%d",&N,&M);
    for(int i=0;i<N;i++){
        scanf("%s",s);
        for(int j=0;j<M;j++){
            A[i][j] = s[j];
            if(s[j]=='X'){
                q.push({i,j,0});
            }
            else if(s[j]=='W'){
                visited[i][j] = 1;
            }
        }
    }
    int x,y,d;
    int sum=0,co=0;
    while(!q.empty()){
        x = q.front().x;
        y = q.front().y;
        d = q.front().dist;
        q.pop();
        if(visited[x][y])continue;
        visited[x][y]  =1;
        if(A[x][y]=='A'){
            co++;
            sum+=(d*2);
        }
        for(int i=0;i<4;i++){
            if(x+h[i]>=0&&x+h[i]<N&&y+k[i]>=0&&y+k[i]<M){
                q.push({x+h[i],y+k[i],d+1});
            }
        }
    }printf("%d %d",co,sum);

}
