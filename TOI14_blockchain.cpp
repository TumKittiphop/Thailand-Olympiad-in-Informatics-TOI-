#include<bits/stdc++.h>
using namespace std;
int N,M,cou,x,y,A;
bool ch;

typedef pair<int,int> ii;
struct HASH{
    size_t operator()(const ii &a)const{
        return a.first + a.second;
    }
};
unordered_map<ii,int,HASH> um[1005];
unordered_map<ii,int,HASH>::iterator it;
int Ver[1005];
ii temp[1005];
int main(){
    scanf("%d%d",&N,&M);
    for(int i=0;i<N;i++){
        scanf("%d",&Ver[i]);
        for(int j=0;j<Ver[i]-1;j++){
            scanf("%d %d",&x,&y);
            if(x>y)swap(x,y);
            um[i][{x,y}] = 1;
        }
    }
    while(M--){
        cou =0;
        scanf("%d",&A);
        for(int j=0;j<A-1;j++){
            scanf("%d %d",&temp[j].first,&temp[j].second);
            if(temp[j].first>temp[j].second)swap(temp[j].first,temp[j].second);
        }
        for(int t=0;t<N;t++){
            if(A!=Ver[t])continue;
                ch = true;
                for(int i=0;i<A-1;i++){
                    it = um[t].find({temp[i].first,temp[i].second});
                    if(it==um[t].end()){
                        ch = false;
                        break;
                    }
                }
                if(ch){
                    cou++;
                }

        }printf("%d\n",cou);
    }
}
