#include<bits/stdc++.h>
using namespace std;
int N,a,b;
vector<char> v;
void re(int a,int b){
    if(a==N||b==N){
        for(int i=0;i<v.size();i++){
            printf("%c ",v[i]);
        }printf("\n");return;
    }
    v.push_back('W');
    re(a+1,b);
    v.pop_back();
    v.push_back('L');
    re(a,b+1);
    v.pop_back();
}

int main(){
    scanf("%d",&N);
    scanf("%d %d",&a,&b);
    re(a,b);
}
