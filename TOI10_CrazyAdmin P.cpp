#include<bits/stdc++.h>
using namespace std;
int O,M,Max = INT_MIN;
int A[105];
int main(){
    cin>>M>>O;
    for(int i=0;i<O;i++){
        scanf("%d",&A[i]);
        Max = max(Max,A[i]);
    }
    for(int i=Max;i<=1e9;i++){
        int sum=0;
        int c = 1;
        for(int j=0;j<O;j++){
            if(sum+A[j]>i){
                sum=0;
                c++;
                sum+=A[j];
            }
            else{
                sum+=A[j];
            }
        }
        if(c<=M){
            printf("%d",i);
            return 0;
        }
    }
}
