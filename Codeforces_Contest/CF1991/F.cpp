#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,q,a[N],b[N],m;

signed main(){
    T=1;
    while(T--){
        cin>>n>>q;
        for(int i=1;i<=n;i++)cin>>a[i];
        while(q--){
            int l,r;
            cin>>l>>r;
            if(r-l>75){
                printf("YES\n");
                continue;
            }
            m=0;
            for(int i=l;i<=r;i++)b[++m]=a[i];
            sort(b+1,b+m+1);
            int tag=0;
            for(int i=1;i<=m-5;i++){
                if(b[i]+b[i+3]>b[i+4]&&b[i+1]+b[i+2]>b[i+5])tag=1;
            }
            if(tag){
                printf("YES\n");
                continue;
            }
            int c=0;
            for(int i=3;i<=m;i++){
                if(b[i-2]+b[i-1]>b[i]){
                    ++c;
                    int p=i-2;
                    while(p>1&&b[p-1]+b[p]>b[i])--p;
                    int pp=p;
                    while(pp>1&&b[pp-1]+b[p+1]>b[i])--pp;
                    int _m=0;
                    for(int j=1;j<=m;j++)if(j!=p+1&&j!=pp&&j!=i)b[++_m]=b[j];
                    m=_m;
                    break;
                }
            }
            for(int i=3;i<=m;i++){
                if(b[i-2]+b[i-1]>b[i]){
                    ++c;
                    break;
                }
            }
            if(c>1)printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}


