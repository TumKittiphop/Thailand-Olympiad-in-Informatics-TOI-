#include<bits/stdc++.h>
using namespace std;
pair<int,int> ii[100005];
int N,M,a,b;
struct t{
    int now;
    bitset<100005> ch;
};
int ma[100005];
bitset<100005> visited;
int main(){
    int qwer=5,first,sec,now;
    bool  che,ch;
    t temp;
    queue<t> q;
    while(qwer--){
        scanf("%d %d",&N,&M);
        for(int i=0;i<N;i++){
            scanf("%d %d",&ii[i].first , &ii[i].second);
            ma[i]=0;
            temp.ch[i] =0;
        }
        temp.ch[N]=0;
        ma[N]=0;
        for(int j=0;j<M/2;j++){
            scanf("%d %d",&a,&b);
            ma[a] = b;
            ma[b] = a;
        }
        temp.now = 0;
        while(!q.empty())q.pop();
        q.push(temp);
        ch = false;
        while(!q.empty()){
            t te= q.front();
            now = q.front().now;
            q.pop();
            if(now==N){
                printf("Y");
                ch = true;
                break;
            }

            che=false;
            first = ii[now].first,sec = ii[now].second;
            //printf("%d %d\n",first,sec);
            if(!te.ch[first]){
                if(ma[first]!=0&&te.ch[ma[first]] !=1){
                    te.ch[ma[first]] =1;
                    che = true;
                }
                te.now+=1;
//                printf("FIR :");
//                for(int i=1;i<=N;i++){
//                    printf("%d ",te.ch[i]);
//                }cout<<endl;
                q.push(te);
                te.now-=1;
                if(che)te.ch[ma[first]] =0;
            }
            if(!te.ch[sec]){

                if(ma[sec]!=0&&te.ch[ma[sec]]!=1){
                    te.ch[ma[sec]]=1;
                    che = true;
                }
                te.now+=1;
//                printf("SEC :");
//                for(int i=1;i<=N;i++){
//                    printf("%d ",te.ch[i]);
//                }cout<<endl;
                q.push(te);
                te.now-=1;
                //if(che)te.ch[ma[sec]]=0;
            }

        }
        if(!ch){
            printf("N");
        }
    }
}
