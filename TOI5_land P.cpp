#include<bits/stdc++.h>
using namespace std;
double A[5][5];
double Arr[5][5];
typedef pair<int,int> ii;
vector<ii> v;
int N,M;
double ans=DBL_MAX,temp;
int h[] = {0,0,1,-1,1,-1,1,-1};
int k[] = {1,-1,0,0,1,-1,-1,1};
int main(){
    scanf("%d %d",&N,&M);
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            scanf("%lf",&A[i][j]);
            v.push_back({i,j});
        }
    }

    do{
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                Arr[i][j] = A[i][j];
            }
        }
        temp=0.0;
        for(int i=0;i<v.size();i++){
            int x = v[i].first;
            int y = v[i].second;
            temp+=Arr[x][y];
            for(int j=0;j<8;j++){
                if(x+h[j]>=0&&x+h[j]<N&&y+k[j]>=0&&y+k[j]<M){
                    Arr[x+h[j]][y+k[j]] += double(Arr[x][y]/double(10));
                }
            }
        }
        //cout<<temp<<endl;
        if(temp<ans)ans = temp;

    }while(next_permutation(v.begin(),v.end()));
    printf("%.2lf",ans);
}
