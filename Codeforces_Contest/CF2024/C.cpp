#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n;
struct node{
    int x,y;
    node(int x=0,int y=0):x(x),y(y){}
    bool operator < (const node& _)const{
        if(max(x,y)==max(_.x,_.y))return min(x,y)<min(_.x,_.y);
        return max(x,y)<max(_.x,_.y);
    }
}a[N]; 

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i].x>>a[i].y;
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++)printf("%d %d ",a[i].x,a[i].y);
        printf("\n");
    }
    return 0;
}


