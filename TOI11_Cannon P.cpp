#include<bits/stdc++.h>
using namespace std;
int N,M,K,L,x;
vector<int> v;
int Start[1005];
int main(){
    cin>>N>>M>>K>>L;
    for(int i=0;i<N;i++){
        cin>>x;
        v.push_back(x);
    }
    for(int i=0;i<K;i++){
        for(int j=0;j<M;j++){
            scanf("%d",&Start[j]);
        }
        int sum=0;
        for(int j=0;j<M;j++){
            int FindS = Start[j]-L;
            while(j!=M-1&&Start[j]+L>=Start[j+1]-L){
                j++;
            }
            int FindT = Start[j]+L;
            vector<int>::iterator itS,itT;
            itS = upper_bound(v.begin(),v.end(),FindS);
            itT = lower_bound(v.begin(),v.end(),FindT);
            while(itS!=v.end()&&*itS<FindS)itS++;
            while(itS!=v.begin()&&*(itS-1)>=FindS)itS--;
            while(itT!=v.begin()&&*itT>FindT)itT--;
            while(itT!=v.end()&&*(itT+1)<=FindT)itT++;
            if(*itS<FindS||*itT>FindT)continue;
            if(itS==v.end())itS--;if(itT==v.end())itT--;
            int idxS = itS-v.begin();
            int idxT = itT-v.begin();
            sum+=(idxT-idxS+1);
            //printf("A : %d %d\n",idxS,idxT);
        }
        printf("%d\n",sum);
    }
}
