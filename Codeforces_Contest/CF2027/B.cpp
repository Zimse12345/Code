#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n;
struct node{
    int v,pos;
    node(int v=0,int pos=0):v(v),pos(pos){}
    bool operator < (const node& _)const{return v<_.v;}
}a[N];

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i].v,a[i].pos=i;
        sort(a+1,a+n+1);
        int ans=n;
        for(int i=n,j=n;i>=1;i--){
            if(i==n||a[i].v!=a[i+1].v)j=i;
            ans=min(ans,a[i].pos-1+(n-j));
        }
        printf("%d\n",ans);
    }
    return 0;
}


