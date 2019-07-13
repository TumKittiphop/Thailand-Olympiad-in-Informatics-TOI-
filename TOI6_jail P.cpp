#include<bits/stdc++.h>
using namespace std;
int N,M;
int main(){
    list<int> ls;
    list<int>::iterator lss;
    cin>>N>>M;
    for(int i=1;i<=N;i++){
        //*lss = i;
        ls.push_back(i);
    }list<int>::iterator it1 = ls.begin(),it2;
    for(int i=1;i<=N;i++){
        for(int j=1;j<M;j++){
            it1++;
            if(it1==ls.end()){
                it1=ls.begin();
            }
        }
        it2 = it1;
        it1++;
        if(it1==ls.end()){
            it1 = ls.begin();
        }

        printf("%d ",*it2);
        ls.erase(it2);
    }
}
