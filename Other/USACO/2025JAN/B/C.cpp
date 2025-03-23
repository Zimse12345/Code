#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int n,a[N],b[N],c[N],s;

void f(int l,int r){
    int x=s;
    while(1<=l&&r<=n){
        if(a[l]==b[l])--x;
        if(a[r]==b[r])--x;
        swap(a[l],a[r]);
        if(a[l]==b[l])++x;
        if(a[r]==b[r])++x;
        ++c[x];
        swap(a[l],a[r]);
        --l,++r;
    }
    return;
}

signed main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        cin>>b[i];
        if(a[i]==b[i])++s;
    }
    for(int i=1;i<=n;i++){
        f(i,i);
        if(i<n)f(i,i+1);
    }
    for(int i=0;i<=n;i++)printf("%d\n",c[i]);
    return 0;
}


