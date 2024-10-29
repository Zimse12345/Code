#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int n,a[N],b[N];

void f(int l,int r,int t){
    for(int i=r;i>=l;i--){
        int v=t;
        if(!v)v=b[i];
        if(a[i]!=v){
            int s=1;
            if(v==s||a[i]==s)s=2;
            if(v==s||a[i]==s)s=3;
            f(l,i-1,s);
            printf("%d %d\n",a[i],v);
            a[i]=v;
        }
    }
}

signed main(){
    freopen("panin.txt","r",stdin);
    freopen("panout.txt","w",stdout);
    
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];
    f(1,n,0);
    printf("0 0\n");
    return 0;
}


