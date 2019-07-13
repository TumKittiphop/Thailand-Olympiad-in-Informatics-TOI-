#include<bits/stdc++.h>
using namespace std;
int N,M,cou,x,y,A;
bool ch;

//typedef pair<int,int> ii;
//struct HASH{
//    size_t operator()(const ii &a)const{
//        return a.first + a.second;
//    }
//};
int um[1050][1050];
int sum[1050];
int Ver[1050];
int temp[1050];
int main(){
    scanf("%d %d",&N,&M);
    for(int i=0;i<N;i++){
        scanf("%d",&Ver[i]);
        for(int j=0;j<Ver[i]-1;j++){
            scanf("%d %d",&x,&y);
            um[i][x]++;
            um[i][y]++;
        }
    }
    while(M--){
        cou =0;
        scanf("%d",&A);
        for(int i=0;i<=A;i++)temp[i]=0;
        for(int j=0;j<A-1;j++){
            scanf("%d %d",&x,&y);
            temp[x]++;
            temp[y]++;
        }
        for(int t=0;t<N;t++){
            if(A!=Ver[t])continue;
            ch = true;
            for(int i=1;i<=A;i++){
                if(temp[i]==um[t][i])continue;
                else{
                    ch = false;
                    break;
                }
            }

            if(!ch)continue;
            cou++;

        }printf("%d\n",cou);
    }
}
