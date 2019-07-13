#include<stdio.h>
#include<iostream>
using namespace std;
int A[30005];
main(){

    int N,J,x,Ans=0;
    scanf("%d %d",&N,&J);
    for(int i=0;i<N;i++)scanf("%d",&A[i]);
    for(int i=0;i<N;i++){
        int fi = A[i]+J;
//        vector<int>::iterator it = lower_bound(A.begin(),A.end(),fi);
//        if(it==A.end())it=A.end()-1;
//        while(*it>fi&&it!=A.begin())it--;
        int L=i,R=N-1;
        while(L<R){
            int mid = ((L+R)/2);
            if(fi<A[mid]){
                R = mid;
            }
            else{
                L=mid+1;
            }
        }
        while(A[L]>fi)L--;
        //cout<<L<<endl;
        Ans = max(Ans,L-i);
    }
    printf("%d",Ans);

}
