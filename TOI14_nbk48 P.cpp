#include<bits/stdc++.h>
using namespace std;
int N,Q;
map<long long,int> ma;
long long A[100005];
vector<long long> Qsum;
int main(){
    cin>>N>>Q;
    A[0]=0;
    //cout<<ma[0];
    for(int i=0;i<N;i++){
        scanf("%lld",&A[i]);
    }
//    for(int i=0;i<N-1;i++){
//        if(A[i]<0){
//            A[i+1]+=A[i];
//            A[i]=0;
//        }
//    }

    Qsum.resize(N);
    Qsum[0] = A[0];
    for(int i=1;i<N;i++){
        Qsum[i]=Qsum[i-1]+A[i];
    }
    long long Money;
    for(int i=0;i<Qsum.size();i++){
        //printf("%d ",Qsum[i]);
        ma[Qsum[i]] = i;
    }
    //cout<<ma[4]<<endl;
    sort(Qsum.begin(),Qsum.end());
    for(int i=1;i<N;i++){
        if(ma[Qsum[i]]<ma[Qsum[i-1]]){
            ma[Qsum[i]] = ma[Qsum[i-1]];
        }
    }
    for(int h=0;h<Q;h++){
        scanf("%lld",&Money);

        vector<long long>::iterator it =lower_bound(Qsum.begin(),Qsum.end(),Money);
        if(it==Qsum.end())it--;
        while(it!=Qsum.begin()&&*it>Money)it--;
        while(it!=Qsum.end()&&*(it+1)<=Money)it++;
        while(it!=Qsum.begin()&&ma[*(it-1)]>ma[*it])it--;
        if(*it>Money)printf("0\n");
        else printf("%d\n",ma[*it]+1);
    }

}
