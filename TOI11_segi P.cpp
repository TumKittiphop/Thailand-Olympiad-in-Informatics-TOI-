#include<bits/stdc++.h>
using namespace std;
bool Ch[3][260][260];
int N;
char s[256];
int A[3][3] = {{2,1,0},{2,1,1},{1,2,1}};
int main(){
    int f=20;
    while(f--){
        scanf("%d%s",&N,s);
        memset(Ch,0,sizeof Ch);
//        for(int i=0;i<N;i++){
//            for(int j=0;j<N;j++){
//                printf("%d%d%d ",Ch[0][i][j],Ch[1][i][j],Ch[2][i][j]);
//            }printf("\n");
//        }
        for(int l=0;l<N;l++){
            for(int i=0,j=l;j<N;j++,i++){
                if(l==0){
                    Ch[s[i]-'0'][i][j] = true;continue;
                }
                for(int k=i;k<j;k++){
                    if(Ch[0][i][k]&&Ch[0][k+1][j])Ch[2][i][j] = true;
					if(Ch[0][i][k]&&Ch[1][k+1][j])Ch[1][i][j] = true;
					if(Ch[0][i][k]&&Ch[2][k+1][j])Ch[0][i][j] = true;
					if(Ch[1][i][k]&&Ch[0][k+1][j])Ch[2][i][j] = true;
					if(Ch[1][i][k]&&Ch[1][k+1][j])Ch[1][i][j] = true;
					if(Ch[1][i][k]&&Ch[2][k+1][j])Ch[1][i][j] = true;
					if(Ch[2][i][k]&&Ch[0][k+1][j])Ch[1][i][j] = true;
					if(Ch[2][i][k]&&Ch[1][k+1][j])Ch[2][i][j] = true;
					if(Ch[2][i][k]&&Ch[2][k+1][j])Ch[1][i][j] = true;
                }
            }
        }
        if(Ch[0][0][N-1]){
            printf("yes\n");
        }
        else printf("no\n");
    }
}
