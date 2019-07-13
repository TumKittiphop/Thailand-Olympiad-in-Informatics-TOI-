#include<bits/stdc++.h>
using namespace std;
string v[30000];
int N,co,c,ii=0;
char ch[15];
int sum[30000];
void F(int n){
    if(n==N){
        string s(ch);
        v[ii]=s;
        sum[ii] = co;
        ii++;
        return;
    }
    ch[n] ='0';
    F(n+1);
    ch[n]= '1' ;
    co++;
    F(n+1);
    co--;

}
int main(){
    scanf("%d",&N);
    F(0);
    //cout<<v.size();
    //for(int i=0;i<sum.size();i++)cout<<sum[i]<<" "<<v[i]<<endl;
    for(int i=0;i<ii;i++){
        for(int j=i+1;j<ii;j++){
            if(abs(sum[i]-sum[j])!=1)continue;
            c=0;
            bool che =true;

            for(int k=0;k<N;k++){
                if(v[i][k]!=v[j][k])c++;
                if(c>1){
                    che =false;
                    break;
                }
            }

            if(che){
                printf("%s %s\n",v[i].c_str(),v[j].c_str());
                //cout<<v[i]<<" "<<v[j]<<endl;
            }
        }
    }
}
