#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
ii P[4][1505];
struct HASH{
    size_t operator()(const ii& a)const{
        return a.first ^ a.second;
    }
};
unordered_map<ii,ii,HASH> um(10000000);
unordered_map<ii,ii,HASH>::iterator it;
int X,Y,N,x,y,first,sec;
int main(){
    scanf("%d%d",&X,&Y);
    scanf("%d",&N);
    for(int i=0;i<4;i++){
        for(int j=0;j<N;j++){
            scanf("%d%d",&P[i][j].first,&P[i][j].second);
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            x = P[1][j].first+P[0][i].first;
            y = P[1][j].second+P[0][i].second;
            um[{x,y}] = {i,j};
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            x = X-(P[3][j].first+P[2][i].first);
            y = Y-(P[3][j].second+P[2][i].second);
            it = um.find({x,y});
            if(it!=um.end()){
                first = it->second.first;
                sec = it->second.second;
                printf("%d %d\n",P[0][first].first,P[0][first].second);
                printf("%d %d\n",P[1][sec].first,P[1][sec].second);
                printf("%d %d\n",P[2][i].first,P[2][i].second);
                printf("%d %d\n",P[3][j].first,P[3][j].second);
                return 0;
            }
        }
    }
}
