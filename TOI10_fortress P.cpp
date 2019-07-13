#include<bits/stdc++.h>
using namespace std;
long long N,M;
int main(){
    for(int a=0;a<20;a++){
        scanf("%lld %lld",&M,&N);
        long long b = (M-(2*N));
        if(b%2!=0||b<0||M%2!=0){
            printf("0\n");
            continue;
        }
        b/=2;
        long long temp = (M-(4*b));
        if(temp%2!=0||temp<0){
            printf("0\n");
            continue;
        }
        //cout<<b<<" ";
        printf("%lld\n",(temp/2)+1);
    }
}
