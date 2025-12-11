#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,p[N],m;

void sol(int l,int r){
    if(l==r)return;
    int mid=(l+r)/2,lm=m,rm=m;
    for(int i=l;i<=r;i++){
        if(i<=mid)lm=min(lm,p[i]);
        else rm=min(rm,p[i]);
    }
    if(rm<lm){
        for(int d=0;l+d<r-d;d++)swap(p[l+d],p[r-d]);
    }
    sol(l,mid),sol(mid+1,r);
    return;
}

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        m=(1<<n);
        for(int i=0;i<m;i++){
            cin>>p[i];
        }
        sol(0,m-1);
        for(int i=0;i<m;i++)printf("%d ",p[i]);
        printf("\n");
    }
    return 0;
}


