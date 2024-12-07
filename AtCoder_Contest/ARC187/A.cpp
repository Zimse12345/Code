#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int n,k,a[N],ans[N],m; 

signed main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=2;i<n;i++){
        while(a[i]<a[i-1])a[i]+=k,a[i+1]+=k,ans[++m]=i,ans[++m]=i;
    }
    if(a[n]<a[n-1]){
        if(a[n]+k>a[n-1]){
            if(n==2){
                printf("No\n");
                return 0;
            }
            while(a[n]<a[n-2]){
                a[n-1]+=k,a[n]+=k;
                ans[++m]=n-1,ans[++m]=n-1;
            }
            int t=a[n-2];
            a[n-2]=a[n-1]+k;
            a[n-1]=t;
            ans[++m]=n-2;
            while(a[n-1]<a[n-2])a[n-1]+=k,a[n]+=k,ans[++m]=n-1,ans[++m]=n-1;
        }
        else{
            int t=a[n-1];
            a[n-1]=a[n]+k;
            a[n]=t;
            ans[++m]=n-1;
            while(a[n-1]<a[n-2])a[n-1]+=k,a[n]+=k,ans[++m]=n-1,ans[++m]=n-1;
        }
    }
    int tag=0;
    for(int i=1;i<n;i++)if(a[i]>a[i+1])tag=1;
    if(tag)printf("No\n");
    else{
        printf("Yes\n");
        printf("%d\n",m);
        for(int i=1;i<=m;i++)printf("%d ",ans[i]);
    }
    return 0;
}


