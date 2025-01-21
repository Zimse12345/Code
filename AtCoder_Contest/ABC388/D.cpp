#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int n,a[N],b[N];

signed main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]+=b[i-1];
        a[i]+=b[i];
        int l=i+1,r=min(i+a[i],n);
        ++b[l],--b[r+1];
        a[i]-=r-l+1;
    }
    for(int i=1;i<=n;i++){
        printf("%d ",a[i]);
    }
    return 0;
}


