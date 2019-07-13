#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
vector<ii> v;
map<int,int> ma;
int N,x,y;
double ans;
int A[100005];
int dp[100005];
int t[100005];
void dc(int lb,int ub){
    if(lb==ub)return;
    int mid = (lb+ub)/2;
    dc(lb,mid);
    dc(mid+1,ub);

    dp[mid] = ma[A[mid]];
    for(int i=mid-1;i>=lb;i--){
        dp[i] = dp[i+1] + ma[A[i]];
        //cout<<A[i]<<" "<<dp[idx]<<endl;
    }
//    for(int i=0;i<N;i++)printf("%d ",A[i]);
//    printf("\n DP:");
//    for(int i=0;i<N;i++)printf("%d ",dp[i]);
//    printf("\n");
    int tl = lb,tm = mid+1,a=lb;
    //printf("SS : %d %d %d\n",lb,mid,ub);
    while(tl<=mid&&tm<=ub){
        if(A[tl]>A[tm]){

            ans+=double(dp[tl])+double(ma[A[tm]])*double(mid-tl+1);
            //printf("%d %d %d %d %d\n",A[tl],A[tm],(dp[tl]),ma[A[tm]],(mid-tl+1));
            t[a++] = A[tm++];
        }
        else{

            t[a++] = A[tl++];
            //printf("A %d %d\n",A[tl],A[tm]);
        }
    }
    while(tl<=mid)t[a++]=A[tl++];
    while(tm<=ub)t[a++] = A[tm++];
    for(int i=lb;i<=ub;i++)A[i] = t[i];

}
int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d %d",&x,&y);
        v.push_back({x,y});
    }
    sort(v.begin(),v.end());
    for(int i=0;i<N;i++){
        ma[v[i].second] = v[i].first;
        A[i] = v[i].second;
    }
    dc(0,N-1);
    printf("%.0f",ans);
}
