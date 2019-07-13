#include<bits/stdc++.h>
using namespace std;
bool ch[30];
vector<int> adj[30];
int E;

bool visited[30][30];
bool dfs(int now,int c){
    //printf("%c %d\n",now+'A',c);
    if(c==E){
        printf("%c ",now+'A');
        return true;
    }

    for(int i=0;i<adj[now].size();i++){
        int x = now,y = adj[now][i];
        if(x>y)swap(x,y);
        if(visited[x][y]==false){
            visited[x][y] = 1;
            if(dfs(adj[now][i],c+1)){
                printf("%c ",now+'A');
                return true;
            }
            visited[x][y] = false;
        }
    }
    return false;
}
int main(){
    scanf("%d",&E);
    for(int i=0;i<E;i++){
        char a[4];
        scanf("%s",a);
        int x= a[0]-'A',y=a[1]-'A';
        ch[x]=true;
        ch[y]=true;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i=0;i<26;i++){
        if(!ch[i])continue;
        if(adj[i].size()%2==0)continue;
        if(dfs(i,0)){
            return 0;
        }
    }
    for(int i=0;i<26;i++){
        if(!ch[i])continue;
        if(dfs(i,0)){
            //printf("HER");
            return 0;
        }
    }

}
