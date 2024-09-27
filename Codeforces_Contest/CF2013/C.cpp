#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,a[N];

bool q(int l,int r){
    printf("? ");
    for(int i=l;i<=r;i++)printf("%d",a[i]);
    printf("\n");
    fflush(stdout);
    int x;
    cin>>x;
    return x;
}

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        int l=n,r=n-1;
        while(r-l+1<n){
            ++r;
            a[r]=0;
            if(q(l,r))continue;
            a[r]=1;
            if(q(l,r))continue;
            --r;
            break;
        }
        while(r-l+1<n){
            --l;
            a[l]=0;
            if(q(l,r))continue;
            a[l]=1;
        }
        printf("! ");
        for(int i=l;i<=r;i++)printf("%d",a[i]);
        printf("\n");
        fflush(stdout);
    }
    return 0;
}


