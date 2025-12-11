#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6;
int T,n,m,a[N];

bool ck(int L){
    int s=0;
    for(int i=1;i<=n;i++)s+=a[i]/L;
    return s<=m;
}

signed main(){
    scanf("%lld",&T);
    while(T--){
        scanf("%lld%lld",&n,&m);
        for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
        int L=1,R=2e9,ans=0;
        while(L<=R){
            int M=(L+R)/2;
            if(ck(M))ans=M,R=M-1;
            else L=M+1;
        }
        printf("%lld\n",ans);
    }
    return 0;
}


