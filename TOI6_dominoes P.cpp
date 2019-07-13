#include<bits/stdc++.h>
using namespace std;
int N;
int sum=0;
int A[15];
vector<vector<int> > Ans;
map<vector<int> ,bool> ma;
void F(int lv){
    if(sum>N||lv>N){
        return;
    }
    if(sum==N&&lv==N){
        vector<int> V;
        for(int i=0;i<lv;i++){
            if(A[i]==1){
                V.push_back(1);
            }
            if(A[i]==2){
                V.push_back(2);
            }
        }
        if(ma[V])return;
        ma[V] = true;
        return ;
    }
    A[lv]=0;
    F(lv+1);
    A[lv]=1;
    sum++;
    F(lv+1);
    sum--;
    A[lv]=2;
    sum+=2;
    F(lv+1);
    sum-=2;

}
int main(){
    cin>>N;

    F(0);
    //printf("%d  ",Ans.size());
    map<vector<int>,bool>::iterator it;

    for(it=ma.begin();it!=ma.end();it++){
        vector<int> t = it->first;
        for(int i=0;i<t.size();i++){
            if(t[i]==1){
                printf("--\n");
            }
            else if(t[i]==2){
                printf("||\n");
            }
        }printf("E\n");
    }
}
