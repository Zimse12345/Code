#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6;
int T,n,a[N];

bool ck(int t){
    int l=1,r=n;
    while(l+1<r){
        if(t){
            --r;
            if(a[l]*a[l]!=a[r]*a[r+1])return false;
        }
        else{
            ++l;
            if(a[r]*a[r]!=a[l]*a[l-1])return false;
        }
        t^=1;
    }
    return true;
}

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        sort(a+1,a+n+1);
        if(n==2){
            printf("Yes\n");
            continue;
        }
        int tag=1;
        if(a[1]*a[n]>0){
            for(int i=2;i<n;i++){
                if(a[i]*a[i]!=a[i-1]*a[i+1])tag=0;
            }
        }
        else{
            if(ck(0)||ck(1))tag=1;
            else tag=0;
        }
        if(tag)printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}


