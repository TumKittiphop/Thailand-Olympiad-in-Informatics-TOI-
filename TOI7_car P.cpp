#include<bits/stdc++.h>
using namespace std;
int A[105][45];
int N,M,st;
vector<int> v;
int dfs(int i,int j){
    if(i==N-1){
        //printf("A %d",A[i][j]);
        return 1;
    }

    if(j+1>=0&&j+1<M){
        if(A[i+1][j+1]==0){
            int t = dfs(i+1,j+1);
            if(t==1){
                v.push_back(2);
                return 1;
            }
        }
    }
    if(j>=0&&j<M){
        if(A[i+1][j]==0){
            int t = dfs(i+1,j);
            if(t==1){
                v.push_back(3);
                return 1;
            }
        }
    }
    if(j-1>=0&&j-1<M){
        if(A[i+1][j-1]==0){
            int t =dfs(i+1,j-1);
            if(t==1){
                v.push_back(1);
                return 1;
            }
        }
    }
    return 0;
}
int main(){
    cin>>M>>st>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            scanf("%d",&A[i][j]);
        }
    }
    dfs(-1,st-1);
    for(int i=v.size()-1;i>=0;i--){
        printf("%d\n",v[i]);
    }
}
