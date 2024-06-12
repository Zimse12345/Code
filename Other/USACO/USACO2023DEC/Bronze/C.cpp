#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6,INF=1e18;
int T,n;
struct node{
    int x,y,z;
    node(int x=0,int y=0,int z=0):x(x),y(y),z(z){}
    bool operator < (const node& _)const{return z>_.z;}
}a[N];

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i].x;
        for(int i=1;i<=n;i++)cin>>a[i].y;
        for(int i=1;i<=n;i++)cin>>a[i].z;
        sort(a+1,a+n+1);
        int t=0;
        for(int i=2;i<=n;i++){
            if(a[i].x<=a[i-1].x){
                if(a[i].y<=a[i-1].y)t=INF;
                else{
                    int k=(a[i].y-a[i-1].y);
                    t=max(t,(a[i-1].x-a[i].x)/k+1);
                }
            }
        }
        if(t<INF){
            a[0].x=-1;
            for(int i=1;i<=n;i++){
                a[i].x+=a[i].y*t;
                if(a[i].x<=a[i-1].x){
                    t=INF;
                    break;
                }
            }
        }
        if(t==INF)t=-1;
        printf("%lld\n",t);
    }
    return 0;
}


