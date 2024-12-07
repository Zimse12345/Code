#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6;
int T,n,k,a[N];
char s[N];

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>k;
        scanf("%s",s+1);
        for(int i=1;i<=n;i++){
            if(s[i]=='0')a[i]=-1;
            else a[i]=1;
        }
        for(int i=n-1;i>=1;i--)a[i]+=a[i+1];
        int v=0,t=n;
        sort(a+2,a+n+1);
        while(t>1&&v<k)v+=a[t],--t;
        if(v<k)printf("-1\n");
        else printf("%lld\n",n-t+1);
    }
    return 0;
}


