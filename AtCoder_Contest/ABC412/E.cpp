#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e7;
int L,R,p[N],n;
int pr[N],prime[N],cnt;

signed main(){
    for(int i=2;i<N;i++){
        if(!pr[i])prime[++cnt]=i;
        for(int j=1;j<=cnt&&i*prime[j]<N;j++){
            pr[i*prime[j]]=1;
        }
    }
    cin>>L>>R;
    n=R-L;
    for(int i=2;i<N;i++)if(!pr[i]){
        int l=L/i,r=R/i;
        if(l*i<L)++l;
        for(int j=l;j<=r;j++){
            int x=j*i;
            ++p[x-L];
            int y=x;
            while(y%i==0)y/=i;
            if(y!=1)++p[x-L];
        }
    }
    p[0]=0;
    int ans=0;
    for(int i=0;i<=n;i++)if(p[i]==0||p[i]==1)++ans;
    printf("%lld\n",ans);
    return 0;
}


