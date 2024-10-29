#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6,inf=1e9;
int T,n,a[N],l[N],r[N],c[N];

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++)l[i]=inf,r[i]=-inf,c[i]=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            l[a[i]]=min(l[a[i]],i);
            r[a[i]]=max(r[a[i]],i);
        }
        int L=inf,R=-inf,ans=0;
        for(int i=1;i<=n;i++){
            c[max(i-a[i]+1,1)]++;
            c[min(i+a[i]-1,n)+1]--;
            L=min(L,l[i]),R=max(R,r[i]);
            if(i<R-L+1){
                ans=-1;
                break;
            }
        }
        if(ans!=-1){
            for(int i=1;i<=n;i++){
                c[i]+=c[i-1];
                if(c[i]==n)ans++;
            }
        }
        else ans=0;
        printf("%d\n",ans);
    }
    return 0;
}


