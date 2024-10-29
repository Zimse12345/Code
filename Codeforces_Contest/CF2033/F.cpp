#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=5.01e6,Mod=1000000007;
int T,n,m,a[N],p[N];

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>m;
        int id=n;
        if(m>1){
            int cnt=0,tot=0;
            a[++cnt]=1,a[++cnt]=1;
            while(1){
                ++cnt;
                a[cnt]=(a[cnt-1]+a[cnt-2])%m;
                if(a[cnt]%m==0)p[++tot]=cnt;
                if(a[cnt]==1&&a[cnt-1]==1)break;
            }
            cnt-=2;
            p[0]=p[tot];
            id=(n-1)/tot%Mod*cnt+p[n%tot];
        }
        printf("%lld\n",id%Mod);
    }
    return 0;
}


