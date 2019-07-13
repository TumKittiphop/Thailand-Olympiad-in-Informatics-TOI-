#include<bits/stdc++.h>
using namespace std;
int N,sum,st,en;
int Ans[1005][1005];
string c;

int main(){
    char temp;
    scanf("%d",&N);

    for(int i=0;i<N;i++){
        scanf("%s",&temp);
        c+=temp;
    }
    for(int l=1;l<N;l++){
        for(int i=0,j=l;j<N;i++,j++){
            for(int k=i;k<j;k++){
                if(c[i]==c[j]){
                    Ans[i][j] = 1+Ans[i+1][j-1];
                    break;
                }
                Ans[i][j] = max(Ans[i][j],Ans[i][k]+Ans[k+1][j]);
            }
        }
    }
    printf("%d",Ans[0][N-1]);

}
