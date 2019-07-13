#include<bits/stdc++.h>
using namespace std;
int N,M,x,y,st,u,v,aa;

typedef pair<int,int> ii;

struct t{
    int now,x,y;
};
//1 on top of 2
//1 at left side of 2
int A[300][300];
bool visited[40005];
bitset<40005> visited2;
vector<ii> vv[40005];
int main(){
    scanf("%d %d",&N,&M);
    ii s;
    int T = (N*M)-1;
    char cha[3];
    for(int i=0;i<T;i++){
        scanf("%d",&x);
        scanf("%s",cha);
        scanf("%d",&y);
        if(cha[0]=='U'){
            vv[x].push_back({1,y});
            //s = "D"+to_string(x);
            vv[y].push_back({3,x});
        }
        else{
            //s="L"+to_string(y);
            vv[x].push_back({4,y});
            //s="R"+to_string(x);
            vv[y].push_back({2,x});
        }
    }
    int stx,sty;
    bool ch;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            u =i,v=j;
            queue<t> q;
            q.push({0,i,j});
            ch=true;
            fill(visited,visited+40000,0);
            //printf("R :%d %d",i,j);
            while(!q.empty()){
                int now = q.front().now;
                int xx = q.front().x;
                int yy = q.front().y;
                q.pop();

                if(visited[now]==true)continue;
                visited[now] = true;

                for(int l=0;l<vv[now].size();l++){
                    s = vv[now][l];
                    aa = s.first;
                    //cout<<s<<endl;
                    if(aa==1){
                        if(xx<0||xx>=N||yy<0||yy>=M){
                            ch = false;
                            break;
                        }
                        q.push({s.second,xx+1,yy});
                    }
                    else if(aa==3){
                        if(xx<0||xx>=N||yy<0||yy>=M){
                            ch = false;
                            break;
                        }
                        q.push({s.second,xx-1,yy});
                    }
                    else if(aa==4){
                        if(xx<0||xx>=N||yy<0||yy>=M){
                            ch = false;
                            break;
                        }
                        q.push({s.second,xx,yy+1});
                    }
                    else if(aa==2){
                        if(xx<0||xx>=N||yy<0||yy>=M){
                            ch = false;
                            break;
                        }
                        q.push({s.second,xx,yy-1});
                    }
                }
            }
            if(ch){
                stx=i,sty=j;

                break;
            }
        }
        if(ch){
            queue<t> q;
            q.push({0,stx,sty});
            //for(int k=0;k<=40000;k++)visited[k] = 0;
            //printf("R :%d %d",i,j);
            while(!q.empty()){
                int now = q.front().now;
                int xx = q.front().x;
                int yy = q.front().y;q.pop();
                if(visited2[now]==true)continue;
                visited2[now] = true;
                A[xx][yy] = now;

                for(int l=0;l<vv[now].size();l++){
                    s = vv[now][l];
                    aa  =s.first;
                    //cout<<now<<" "<<s<<endl;
                    if(aa==1){
                        q.push({s.second,xx+1,yy});
                    }
                    else if(aa==3){
                        q.push({s.second,xx-1,yy});
                    }
                    else if(aa==4){
                        q.push({s.second,xx,yy+1});
                    }
                    else if(aa==2){
                        q.push({s.second,xx,yy-1});
                    }
                }
            }break;
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            printf("%d ",A[i][j]);
        }printf("\n");
    }

}
