#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int n,m;
struct node{
    int x,y;
    char c;
    node(int x=0,int y=0,char c=0):x(x),y(y),c(c){}
    bool operator < (const node& _)const{return x<_.x;}
}a[N];

signed main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>a[i].x>>a[i].y>>a[i].c;
    }
    sort(a+1,a+m+1);
    int b=n;
    for(int l=1,r;l<=m;){
        r=l;
        while(r<m&&a[r+1].x==a[r].x)++r;
        int rb=0,lw=n+1;
        for(int i=l;i<=r;i++){
            if(a[i].c=='W')lw=min(lw,a[i].y);
            else rb=max(rb,a[i].y);
        }
        if(rb>b||rb>lw){
            printf("No\n");
            return 0;
        }
        b=min(b,lw-1);
        l=r+1;
    }
    printf("Yes\n");
    return 0;
}


