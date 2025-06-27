#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6;
int T,n,m,u[N],v[N],k;
int st[N],t;

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>m;
        t=k=0;
        for(int i=n,f=0;i>=1;i--){
            if(i+t+(i-1)<=m&&m<=(1+i)*i/2+t*i){
                ++k,u[k]=f,v[k]=i;
                f=i;
                m-=i;
                while(t&&(t-1)+(i-1)+i<=m){
                    ++k;
                    u[k]=f,v[k]=st[t],--t;
                    m-=i;
                }
            }
            else{
                st[++t]=i;
            }
        }
        if(k!=n||m!=0){
            printf("-1\n");
            continue;
        }
        printf("%lld\n",v[1]);
        for(int i=2;i<=n;i++)printf("%lld %lld\n",u[i],v[i]);
    }
    return 0;
}


