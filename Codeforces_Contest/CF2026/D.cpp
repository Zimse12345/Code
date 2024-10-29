#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6;
int n,a[N],s[N],q;
int f[N],sf[N],ss[N];

int calc(int x){
    int L=0,R=n,t=0;
    while(L<=R){
        int M=(L+R)/2;
        if((n+n-M+1)*M/2<=x)t=M,L=M+1;
        else R=M-1;
    }
    int res=sf[t];
    int l=t+1,r=t+(x-(n+n-t+1)*t/2);
    if(1<=l&&l<=n&&l<=r&&r<=n){
        res+=(ss[r]-ss[l-1])-(s[r]-s[l-1])*(n-l+1-(r-l+1));
    }
    return res;
}

signed main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[i]=s[i-1]+a[i];
        f[1]+=a[i]*(n-i+1);
        ss[i]=ss[i-1]+a[i]*(n-i+1);
    }
    sf[1]=f[1];
    for(int i=2;i<=n;i++){
        f[i]=f[i-1]-a[i-1]*(n-i+2);
        sf[i]=sf[i-1]+f[i];
    }
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        printf("%lld\n",calc(r)-calc(l-1));
    }
    return 0;
}


