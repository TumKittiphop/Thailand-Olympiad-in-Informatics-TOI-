#include<bits/stdc++.h>
using namespace std;
int A[5000010];
string s,temp;
int N;

int main(){
    scanf("%d",&N);
    cin>>s;
    temp =s;
    int st = N;
    s  = s+s;


    int i =0,j=1;
    //cout<<s<<endl;
    while(j<N){
        //printf("%d %d %c %c\n",i,j,temp[i],temp[j]);
        if(temp[i]==temp[j]){
            A[j] = i+1;
            i++;j++;
        }
        else{
            if(i!=0){
                i = A[i-1];
            }
            else{
                A[j] =0;
                j++;
            }
        }
    }
//    for(int i=0;i<=N;i++){
//        printf("%d ",A[i]);
//    }cout<<endl;
    j=1,i=0;
    //bool ch=0;
    while(j<2*N){
        //printf("%d %d %c %c\n",i,j,s[i],temp[j]);
        if(s[j]==temp[i]){
            i++,j++;
        }
        else{
            if(i!=0){
                i = A[i-1];
            }
            else{
                j++;
            }
        }
        if(i==N){
            break;
        }
    }
    //printf("A %d\n",ch);
    //if(ch)
    printf("%d",(j-N));

}
