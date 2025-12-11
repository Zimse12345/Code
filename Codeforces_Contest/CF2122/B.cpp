#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,a[N],b[N],c[N],d[N];

int _abs(int x){
    return x<0?-x:x;
}

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        long long s=0;
        for(int i=1;i<=n;i++){
            cin>>a[i]>>b[i]>>c[i]>>d[i];
            if(d[i]<b[i])s+=a[i]+b[i]-d[i];
            else if(a[i]>c[i])s+=a[i]-c[i];
        }
        printf("%lld\n",s);
    }
    return 0;
}


