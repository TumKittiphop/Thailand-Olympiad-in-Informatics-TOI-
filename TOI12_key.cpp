#include<bits/stdc++.h>
using namespace std;
int N,len1,len2;
bool A[1005][1005][105];
char s1[1005];
char s2[1005];
char s3[1005];
int AA,BB,Ac,Bc,l;
int main(){
    vector<int> v;
    scanf("%s %s",s1,s2);
    len1 = strlen(s1);
    len2 = strlen(s2);
    scanf("%d",&N);
    for(int x=0;x<N;x++){
        scanf("%s",s3);
        for(int i=0;i<=len1;i++){
            for(int j=0;j<=len2;j++){
                l = i+j-1;
                if(i==0&&j==0){
                    A[i][j][x] = true;
                }
                else if(i==0){
                    if(s3[l]==s2[j-1]){
                        A[i][j][x]=A[i][j-1][x];
                    }
                }
                else if(j==0){
                    if(s3[l]==s1[i-1]){
                        A[i][j][x]=A[i-1][j][x];
                    }
                }
                else{
                    A[i][j][x] = (s3[l]==s2[j-1]?A[i][j-1][x]:false)||(s3[l]==s1[i-1]?A[i-1][j][x]:false);
                }
            }
        }
        if(A[len1][len2][x]){
            printf("Yes\n");
        }
        else{
            printf("No\n");
        }
    }
}
