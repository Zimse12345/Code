#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6;
int T,n,w,fa[N],x[N],y[N],ans[N],q[N],pre[N],p[N],c[N];

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>w;
        for(int i=1;i<=n;i++)ans[i]=c[i]=0;
        for(int i=2;i<=n;i++)cin>>fa[i];
        for(int i=2;i<=n;i++){
            cin>>x[i]>>y[i];
            q[x[i]]=i;
        }
        for(int i=2;i<=n;i++)pre[i]=pre[i-1]+y[i];
        for(int i=1;i<=n;i++){
            int j=i%n+1;
            int pos=i;
            int m=0;
            while(pos!=fa[j]&&pos!=1)p[++m]=q[pos],pos=fa[pos];
            if(j>1)p[++m]=q[j];
            sort(p+1,p+m+1);
            for(int t=1;t<=m;t++){
                ans[p[t]]+=y[p[t]];
            }
            ++c[p[m]];
        }
        for(int i=2;i<=n;i++){
            ans[i]+=ans[i-1];
            c[i]+=c[i-1];
            printf("%lld ",ans[i]+(w-pre[i])*(n-c[i]));
        }
        printf("\n");
    }
    return 0;
}


