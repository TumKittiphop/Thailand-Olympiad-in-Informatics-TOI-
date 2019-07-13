#include<bits/stdc++.h>
using namespace std;
int A[2000005];
int N;
int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++)scanf("%lld",&A[i]);
    long long L = 0,R = LLONG_MAX;
    while(L!=R){
        long long mid = (L+R)/2;
        //printf("%lld %lld\n",L,R);
        long long ch=0;
        bool check=false;
        for(int i=0;i<N;i++){
            if(A[i]>mid){
                if(ch==0){
                    ch = A[i];
                }
                else{
                    if(A[i]==ch){ch=0;continue;}
                    else{
                        check=true;
                        break;
                    }
                }
            }
        }
        if(check){
            L = mid+1;
        }
        else{
            R = mid;
        }
    }cout<<L;
}
