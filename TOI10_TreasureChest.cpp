#include<bits/stdc++.h>
using namespace std;
int A[200000005],idx=0;
void build(int idx,int left,int right){
    if(left ==right){
        seg[idx] = A[left];
    }
    else{
        build(idx*2+1,left,(left+right)/2);
        build(idx*2+2,(left+right)/2,right);
        int l = seg[idx*2+1];
        int r = seg[idx*2+2];
        seg[idx] = max(l,r);
    }
}
void
int main(){
    scanf("%d %d",&M,&N);
    vector<int> seg,lazy;
    fill(A,A+N+1,1);

}
