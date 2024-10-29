#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6,inf=1e18;
int T,x,y,z,k;

inline int ck(int p){
    int sum=p*x;
    int t=(p-1)/k;
    sum+=t*y;
    int rm=z-t*(t+1)/2*k;
    if(rm>0)sum+=((rm-1)/p+1)*y;
    return sum;
}

inline int ckk(int p){
    //[pk+1,pk+k]
    int res=inf;
    int rm=z-p*(p+1)/2*k-1;
    for(int l=p*k+1;l<=p*k+k;){
        int r=p*k+k;
        if(rm/l)r=rm/(rm/l);
        r=min(r,p*k+k);
        res=min(res,ck(l));
        l=r+1;
    }
    return res;
}

signed main(){
    cin>>T;
    while(T--){
        cin>>x>>y>>z>>k;
        int ans=inf;
        for(int i=0;i<=20000&&i<=z/k+1;i++)ans=min(ans,ckk(i));
        printf("%lld\n",ans);
    }
    return 0;
}


