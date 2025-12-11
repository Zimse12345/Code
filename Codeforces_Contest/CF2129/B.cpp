#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,a[N],p[N];

int calc(int x){
    int res=0;
    for(int i=1;i<x;i++)if(a[i]>a[x])++res;
    for(int i=x+1;i<=n;i++)if(a[i]<a[x])++res;
    return res;
}

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            p[a[i]]=i;
        }
        for(int i=1;i<=n;i++){
            int x=p[i];
            int A=calc(x);
            a[x]=n*2-a[x];
            int B=calc(x);
            if(B>A)a[x]=n*2-a[x];
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++)if(a[i]>a[j])++ans;
        }
        printf("%d\n",ans);
    }
    return 0;
}


