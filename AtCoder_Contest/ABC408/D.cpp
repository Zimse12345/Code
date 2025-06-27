#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,a[N],f[N],g[N],h[N];
char s[N];

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        scanf("%s",s+1);
        for(int i=1;i<=n;i++){
            a[i]=s[i]-'0';
            f[i]=f[i-1]+a[i];
            g[i]=min(f[i-1],g[i-1])+(a[i]^1);
            h[i]=min(min(h[i-1],g[i-1]),f[i-1])+a[i];
        }
        printf("%d\n",min(min(f[n],g[n]),h[n]));
    }
    return 0;
}


