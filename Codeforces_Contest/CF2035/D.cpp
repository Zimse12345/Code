#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6,M=8.01e6,Mod=1000000007;
int T,n,a[N],p2[M],c[N],stk[N],top;

int calc(int id){
    int x=a[id],cnt=c[id];
    while(cnt>0&&x<1e9)--cnt,x*=2;
    return x;
}

signed main(){
    p2[0]=1;
    for(int i=1;i<M;i++)p2[i]=(p2[i-1]*2)%Mod;
    cin>>T;
    while(T--){
        cin>>n;
        top=0;
        int sum=0;
        for(int i=1;i<=n;i++){
            c[i]=0;
            cin>>a[i];
            while(a[i]%2==0)a[i]/=2,++c[i];
            sum=(sum+a[i]*p2[c[i]])%Mod;
            while(top&&a[stk[top]]<calc(i)){
                int t=stk[top];
                sum=(sum-a[t]*p2[c[t]]+a[t]+a[i]*p2[c[t]+c[i]]-a[i]*p2[c[i]])%Mod;
                c[i]+=c[t];
                --top;
            }
            if(c[i])stk[++top]=i;
            printf("%lld ",(sum+Mod)%Mod);
        }
        printf("\n");
    }
    return 0;
}


