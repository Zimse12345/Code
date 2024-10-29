#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int n,ans,h[N];
struct node{
    int x,y;
    node(int x=0,int y=0):x(x),y(y){}
    bool operator < (const node& _)const{
        if(y==_.y)return x<_.x;
        return y<_.y;
    }
}p[N];
struct _node{
    int x,y;
    _node(int x=0,int y=0):x(x),y(y){}
    bool operator < (const _node& _)const{
        return x<_.x;
    }
}_p[N];

signed main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>p[i].x>>p[i].y;
        _p[i].x=p[i].x,_p[i].y=p[i].y;
    }
    sort(p+1,p+n+1);
    sort(_p+1,_p+n+1);
    for(int l=1,r;l<=n;){
        r=l;
        while(r<n&&p[r+1].y==p[r].y)++r;
        for(int i=l;i<r;i++){
            int t=1,h=p[l].y;
            while(t<=n&&_p[t].x<=p[i].x)++t;
            for(int j=i+1;j<=r;j++){
                while(t<=n&&_p[t].x<p[j].x)h=min(h,_p[t].y),++t;
                if(p[j].x-p[i].x<=p[r].y-h){
                    ans=max(ans,p[j].x-p[i].x+p[r].y-h);
                }
            }
        }
        l=r+1;
    }
    printf("%d\n",ans);
    return 0;
}


