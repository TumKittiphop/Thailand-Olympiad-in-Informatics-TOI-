#include<bits/stdc++.h>
using namespace std;
int N,x,y,W,R,D;
typedef pair<int,int> ii;
vector<ii> point;
ii temp[100010],f;

double dis(ii a,ii b){
    return double(sqrt(double(a.first-b.first)*double(a.first-b.first)+double(a.second-b.second)*double(a.second-b.second)));
}
double min(double a,double b){
    if(a>b)return b;
    return a;
}
double closest(int lb,int ub){
    if(lb>=ub){
        return 1e300;
    }
    if(lb == ub-1){
        if(point[lb]>point[ub]){
            f = point[lb];
            point[lb] = point[ub];
            point[ub] = f;
        }
        //cout<<dis(point[lb],point[ub])<<endl;
        return dis(point[lb],point[ub]);
    }
    int mid = (lb+ub)/2;
    double cl = closest(lb,mid);
    double cr = closest(mid+1,ub);
    double minn = min(cl,cr);
    int xmid = point[mid].first;
    int tl=lb,tm=mid+1,co=lb;
    while(tl<=mid&&tm<=ub){
        if(point[tl]<point[tm]){
            temp[co++] = point[tl++];
        }
        else{
            temp[co++] = point[tm++];
        }
    }
    while(tl<=mid)temp[co++] = point[tl++];
    while(tm<=ub)temp[co++] = point[tm++];
    for(int i=lb;i<=ub;i++){
        point[i] = temp[i];
    }
    for(int i=lb;i<=ub;i++){
        if(double(abs(xmid-point[i].first))<minn){
            for(int j=i+1;j<=ub &&point[j].second-point[i].second<minn;j++){
                //cout<<i<<" "<<j<<" "<<dis(point[i],point[j])<<endl;
                minn = min(minn,dis(point[i],point[j]));
            }
        }
    }
    return minn;
}
int main(){
    scanf("%d",&W);
    for(int h=0;h<W;h++){
        scanf("%d %d %d",&N,&R,&D);
        point.clear();
        for(int a=0;a<N;a++){
            scanf("%d %d",&x,&y);
            point.push_back({x,y});
        }
        sort(point.begin(),point.end());
        double mindis =closest(0,N-1);
        if(mindis>=double(2*R)+double(D)){
            printf("Y\n");
        }
        else printf("N\n");
    }

}
