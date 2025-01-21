#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,a[N]; 

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        int l=1,r=n;
        while(l<=r&&a[l]==0)++l;
        while(l<=r&&a[r]==0)--r;
        if(r<l){
            printf("0\n");
            continue;
        }
        int tag=0;
        for(int i=l;i<=r;i++)if(a[i]==0)tag=1;
        if(!tag)printf("1\n");
        else printf("2\n");
    }
    return 0;
}


