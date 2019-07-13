#include<bits/stdc++.h>
using namespace std;
int Com,x,y,z,m;
int x1,z1,y11;

int visited[35];
struct t{
    long long a,b,c;
};
t Loca[35];
t S[35];
long long Ans = LLONG_MAX;
int A[35];
void F(int n){
    if(n==m){
        int Moni=0,Key=0,Co=0,xx=x,yy=y,zz=z;
        long long money =0;
        for(int i=0;i<m;i++){
            //printf("%d %d %d\n",Moni,Key,Co);
           //cout<<A[i]<<" ";
            Moni+=S[A[i]].a;
            Key+=S[A[i]].b;
            Co+=S[A[i]].c;
            //printf("A  %d %d %d",Moni,Key,Co);

            money+= ((Loca[A[i]].a-xx)*(Loca[A[i]].a-xx)) +((Loca[A[i]].b-yy)*(Loca[A[i]].b-yy))+((Loca[A[i]].c-zz)*(Loca[A[i]].c-zz));

            xx = Loca[A[i]].a;
            yy = Loca[A[i]].b;
            zz = Loca[A[i]].c;
            if(Moni>=Com&&Key>=Com&&Co>=Com){
               // cout<<money<<endl;
                if(Ans>money)Ans =money;

            }
        }//cout<<endl;
        return;
    }
    for(int a=0;a<m;a++){
        if(visited[a]==0){
            visited[a] = 1;
            A[n] =a;
            F(n+1);
            visited[a] = 0;
        }
    }
}

int main(){
    scanf("%d",&Com);
    scanf("%d %d %d",&x,&y,&z);
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        scanf("%d %d %d",&x1,&y11,&z1);
        Loca[i] = {x1,y11,z1};
        scanf("%d %d %d",&x1,&y11,&z1);
        S[i] = {x1,y11,z1};
    }
    if(m==1){
        long long mo =0;
        mo+= ((Loca[0].a -x)*(Loca[0].a -x));
        mo+= ((Loca[0].b -y)*(Loca[0].b -y));
        mo+= ((Loca[0].c -z)*(Loca[0].c -z));
        printf("%lld",mo);
        return 0;
    }
    F(0);
    printf("%lld",Ans);
}
//5
//500 0 0
//7
//91 72 259
//0 1 1
//306 210 374
//2 1 0
//205 423 19
//1 0 0
//312 335 424
//1 2 2
//262 313 453
//0 0 2
//279 124 496
//0 1 0
//411 107 218
//1 0 0
