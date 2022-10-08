#include <cstdio>
#define int long long

const int N=2e6,P=20100403;
int n,m,f[N+9],v[N+9];

int q(int x,int k){int res=1;while(k){
if(k&1)res=res*x%P;x=x*x%P,k>>=1;}return res;}
int C(int x,int y){return f[x]*v[y]%P*v[x-y]%P;}

signed main(){scanf("%d%d",&n,&m);
f[0]=1;for(int i=1;i<=n+m;i++)f[i]=f[i-1]*i%P;
v[n+m]=q(f[n+m],P-2);for(int i=n+m-1;i>=1;i--)v[i]=v[i+1]*(i+1ll)%P;
return !printf("%lld\n",(C(n+m,m)-C(n+m,m-1)+P)%P);}
