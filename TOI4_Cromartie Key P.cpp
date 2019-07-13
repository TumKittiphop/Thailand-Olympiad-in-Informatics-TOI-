#include<bits/stdc++.h>
using namespace std;
int L,K;
int main(){
    cin>>L>>K;
    string s1,s2,key;
    cin>>s1>>s2;
    cin>>key;
    for(int i=0;i<s1.length();i++){
        if(s1[i]>s2[i]){
            swap(s1[i],s2[i]);
        }
    }
    for(int i=0;i<K;i++){
        for(int j=0;j<L;j++){
            if(key[i]>=s1[j]&&key[i]<=s2[j])continue;
            if(key[i]<s1[j])key[i]=s1[j];
            if(key[i]>s2[j])key[i]=s2[j];
        }
    }
    cout<<key;
}
