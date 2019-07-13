#include<bits/stdc++.h>
using namespace std;
bool ch[7368788];
int N;
int main(){
    vector<int> v;
    v.push_back(0);
    v.push_back(2);

    for(int i=3;i<=7368788;i+=2){
        if(!ch[i])v.push_back(i);
        for(int j=i;j<=7368788;j+=i){
            ch[j] = true;
        }
    }
    scanf("%d",&N);
    cout<<v[N];
}
