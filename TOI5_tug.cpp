#include<bits/stdc++.h>
using namespace std;
int main(){
    long long ans=0;
    vector<int> v,V;
    int N,x;
    cin>>N;
    for(int i=0;i<N;i++){
        scanf("%d",&x);
        v.push_back(x);
    }
    for(int i=0;i<N;i++){
        scanf("%d",&x);
        V.push_back(x);
    }
    sort(v.begin(),v.end());
    sort(V.begin(),V.end());
    for(int i=0;i<N;i++){
        ans+=abs(v[i]-V[i]);
    }printf("%lld",ans);
}
