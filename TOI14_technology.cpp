
#include<bits/stdc++.h>
using namespace std;
int N,K,TIME,M,lev,temp;
vector<int> level[200005];
vector<int> v[200005];
int color[200005];
bool visited[200005];
//white=0 gray=1 black =2
int dfs(int now){
    if(now==0){
        return 0;
    }
    if(color[now]==2)return 0;
    color[now] = 1;
    int sum=1,t;
    for(int i=0;i<v[now].size();i++){
        if(color[v[now][i]]==1){
            //printf("A %d \n",v[now][i]);
            return -1;
        }
        else{
            t = dfs(v[now][i]);
        }

        //gray.clear();
        if(t==-1){
            return -1;
        }
        else{
            sum += t;
        }
    }
    color[now] = 2;
    return sum;
    //return 1+summ;
}

int main(){
    scanf("%d %d %d",&N,&K,&TIME);
    for(int i=1;i<=N;i++){
        scanf("%d %d",&lev,&M);
        level[lev].push_back(i);
        if(M==0){
            v[i].push_back(0);
            continue;
        }
        for(int j=0;j<M;j++){
            scanf("%d",&temp);
            v[i].push_back(temp);
        }
    }
//    for(int i=1;i<=N;i++){
//        printf("ST %d \n",i);
//        for(int j=0;j<v[i].size();j++){
//            printf("%d ",v[i][j]);
//        }cout<<endl;
//    }
    int sum=0;
    for(int i=1;i<=K;i++){
        //printf("LV %d\n",i);
        for(int j=0;j<level[i].size();j++){
            //printf("%d ",level[i][j]);

            int temp = dfs(level[i][j]);
            //printf("%d %d\n",level[i][j],temp);
            if(temp==-1){
                if(i-1==0){
                    printf("-1");
                    return 0;
                }
                printf("%d",i-1);
                return 0;
            }
            sum += temp;
            if(sum>TIME){
                if(i-1==0){
                    printf("-1");
                    return 0;
                }
                printf("%d",i-1);
                return 0;
            }
        }
    }
    printf("%d",K);
}
