#include<bits/stdc++.h>
using namespace std;
map<pair<int,int>,int> ma;
int N,x,y;
int main(){
    string s;
    for(int a=0;a<5;a++){
        bool ch = true;
        scanf("%d",&N);
        ma.clear();
        for(int i=0;i<N-1;i++){
            scanf("%d %d",&x,&y);
            if(x<y)swap(x,y);
            ma[{x,y}]++;
        }
        for(int i=0;i<N-1;i++){
            scanf("%d %d",&x,&y);
            if(x<y)swap(x,y);
            if(ma[{x,y}]!=1){
                ch = false;
            }
        }
        if(ch){
            s+= 'Y';
        }else{
            s+= 'N';
        }
    }
    cout<<s;
}
