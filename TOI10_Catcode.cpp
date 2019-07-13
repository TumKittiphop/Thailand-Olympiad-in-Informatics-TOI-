#include<bits/stdc++.h>
using namespace std;
unordered_map<string,int> ma(1000000);
unordered_map<string,int>::iterator it;
bool Ans[100005];
int k,M,N,j,Min,Max,temp,cou;
int main(){
    scanf("%d %d",&k,&M);
    string s,t;
    for(int i=1;i<=k;i++){
        cin>>s;
        ma[s] = i;
    }
    scanf("%d",&N);
    for(int h=0;h<N;h++){
        scanf("%d",&j);
        cin>>s;
        cou=0,Max=0,Min=1000000;
        for(int i=0;i<j-M+1;i++){
            t = s.substr(i,M);
            it = ma.find(t);
            if(it!=ma.end()){
                temp = it->second;
                Ans[temp] = 1;
                cou=1;
                Max = max(Max,temp);
                Min = min(Min,temp);
            }
        }
//        if(se.size()==0){
//            printf("OK\n");
//        }
//        else{
//            sort(se.begin(),se.end());
//            for(int i=0;i<se.size();i++){
//                printf("%d ",se[i]);
//            }printf("\n");
//        }
        if(cou==0){
            printf("OK\n");
            continue;
        }
        for(int i=Min;i<=Max;i++){
            if(Ans[i]){
                printf("%d ",i);
                Ans[i]=0;
            }
        }printf("\n");

    }

}
